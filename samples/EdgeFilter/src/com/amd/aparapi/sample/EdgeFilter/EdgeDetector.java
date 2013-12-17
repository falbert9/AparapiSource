/*************************************************************************
 *  Compilation:  javac EdgeDetector.java
 *  Execution:    java EdgeDetector filename
 * 
 *  Reads in an image from a file, and flips it horizontally.
 *
 *  % java EdgeDetector baboon.jpg
 *
 *************************************************************************/
package com.amd.aparapi.sample.EdgeFilter;

import java.awt.Color;
import com.amd.aparapi.Kernel;
import com.amd.aparapi.Range;

public class EdgeDetector {

    // truncate color component to be between 0 and 255
    public static int truncate(int a) {
        if      (a <   0) return 0;
        else if (a > 255) return 255;
        else              return a;
    }

    public static void main(String[] args) {

        final int[] filter1 = {  -1,  0,  1 ,
                             -2,  0,  2 ,
                             -1,  0,  1 
                          };
        final int[] filter2 = {   1,  2,  1 ,
                              0,  0,  0 ,
                             -1, -2, -1 
                          };

        final Pic pic0 = new Pic("tux.bmp");
        final int width    = pic0.width();
        final int height   = pic0.height();
        final Pic pic1 = new Pic(width, height);

        final int size = (width -2) * (height - 2);

        //System.out.println(height);
        //System.out.println(width);

        final int[] lum = new int[width*height];
        for(int i = 0; i  < width; i++)
        {
            for(int j = 0; j < height; j++)
            {
                lum[i*height + j] = (int) Luminance.lum(pic0.get(i, j));
            }
        }
        final int[] magnitude = new int[(width-2)*(height-2)];
        long startT = System.nanoTime();

        //final int[] xArray = new int[(width-2)*(height-2)];
        //final int[] yArray = new int[(width-2)*(height-2)];
        //for (int y = 1; y < height - 1; y++) {
            //for (int x = 1; x < width - 1; x++) {
       
       Kernel kernel = new Kernel(){
         @Override public void run() {
                int gid = getGlobalId();

                //int gid = (y-1)*(width-2) + (x-1);
                int y = gid/(width-2) + 1;
                int x = gid%(width-2) + 1;
                //xArray[gid] = x;
                //yArray[gid] = y;

                // get 3-by-3 array of colors in neighborhood
                // apply filter
                int grayX = 0, grayY = 0;
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        grayX += lum[(x-1 + i)*height+(y - 1 + j)] * filter1[i*3+j];
                        grayY += lum[(x-1 + i)*height+(y - 1 + j)] * filter2[i*3+j];
                    }
                }
                // int magnitude = 255 - truncate(Math.abs(gray1) + Math.abs(gray2));
                magnitude[gid] = 255 - truncate((int) Math.sqrt(grayX*grayX + grayY*grayY));
                //Color grayscale = new Color(magnitude[gid], magnitude[gid], magnitude[gid]);
                //pic1.set(x, y, grayscale);
            }
        };
        // Execute Kernel.
      kernel.setExecutionMode(Kernel.EXECUTION_MODE.JTP);
      kernel.execute(Range.create((width-2)*(height-2)));
      long endT = System.nanoTime();
      
      for(int id = 0; id < (width-2)*(height-2); id++)
      {
         int y = id/(width-2) + 1;
         int x = id%(width-2) + 1;
         Color grayscale = new Color(magnitude[id], magnitude[id], magnitude[id]);
         pic1.set(x, y, grayscale);
         //System.out.println(xArray[id] + "," + yArray[id]);
      }

      // Report target execution mode: GPU or JTP (Java Thread Pool).
      System.out.println("Execution mode=" + kernel.getExecutionMode());
      System.out.println("Time = " + (endT - startT));
      pic0.show();
      pic1.show();
        // pic1.save("baboon-edge.jpg");
    }

   
}
