mx vm \
 -Djava.library.path=../../com.amd.aparapi.jni/dist \
 -Dcom.amd.aparapi.executionMode=%1 \
 -classpath ../../com.amd.aparapi/dist/aparapi.jar:MatMul.jar \
 com.amd.aparapi.sample.MatMul.Main