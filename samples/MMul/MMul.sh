java \
 -Djava.library.path=../.. \
 -Dcom.amd.aparapi.logLevel=INFO \
 -Dcom.amd.aparapi.executionMode=%1 \
 -classpath ../../aparapi.jar:MMul.jar \
 com.amd.aparapi.sample.MMul.Main
