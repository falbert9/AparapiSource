/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_amd_aparapi_internal_jni_OpenCLJNI */

#ifndef _Included_com_amd_aparapi_internal_jni_OpenCLJNI
#define _Included_com_amd_aparapi_internal_jni_OpenCLJNI
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    getPlatforms
 * Signature: ()Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_getPlatforms
  (JNIEnv *, jobject);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    createProgram
 * Signature: (Lcom/amd/aparapi/device/OpenCLDevice;Ljava/lang/String;)Lcom/amd/aparapi/internal/opencl/OpenCLProgram;
 */
JNIEXPORT jobject JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_createProgram
  (JNIEnv *, jobject, jobject, jstring);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    createKernelJNI
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLProgram;Ljava/lang/String;[Lcom/amd/aparapi/internal/opencl/OpenCLArgDescriptor;)Lcom/amd/aparapi/internal/opencl/OpenCLKernel;
 */
JNIEXPORT jobject JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_createKernelJNI
  (JNIEnv *, jobject, jobject, jstring, jobjectArray);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    invoke
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLKernel;[Ljava/lang/Object;)V
 */
JNIEXPORT void JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_invoke
  (JNIEnv *, jobject, jobject, jobjectArray);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    disposeKernel
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLKernel;)V
 */
JNIEXPORT void JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_disposeKernel
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    disposeProgram
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLProgram;)V
 */
JNIEXPORT void JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_disposeProgram
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    getProfileInfo
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLProgram;)Ljava/util/List;
 */
JNIEXPORT jobject JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_getProfileInfo
  (JNIEnv *, jobject, jobject);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    remap
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLProgram;Lcom/amd/aparapi/internal/opencl/OpenCLMem;J)V
 */
JNIEXPORT void JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_remap
  (JNIEnv *, jobject, jobject, jobject, jlong);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    getBytes
 * Signature: (Ljava/lang/String;)[B
 */
JNIEXPORT jbyteArray JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_getBytes
  (JNIEnv *, jobject, jstring);

/*
 * Class:     com_amd_aparapi_internal_jni_OpenCLJNI
 * Method:    getMem
 * Signature: (Lcom/amd/aparapi/internal/opencl/OpenCLProgram;Lcom/amd/aparapi/internal/opencl/OpenCLMem;)V
 */
JNIEXPORT void JNICALL Java_com_amd_aparapi_internal_jni_OpenCLJNI_getMem
  (JNIEnv *, jobject, jobject, jobject);

#ifdef __cplusplus
}
#endif
#endif
