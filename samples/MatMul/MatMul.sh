mx vm -XX:-BootstrapGraal -XX:CompileThreshold=10 \
 -Djava.library.path=../../com.amd.aparapi.jni/dist \
 -classpath ../../com.amd.aparapi/dist/aparapi.jar:MatMul.jar \
 com.amd.aparapi.sample.MatMul.Main
