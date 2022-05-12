//
// Created by ryuba on 2017/03/26.
//

#include "GetString.h"
#include <string.h>
#include <jni.h>

jstring
__Java_com_gunman_shootinggame2_MainActivity_getStringFromJNI(JNIEnv* env, jobject obj, jint i){
    char buff[256];
    sprintf(buff,"Hello, World! i = %d\n",i);

//    return (*env)->NewStringUTF(env, "Hello, World!\n");
    return (*env)->NewStringUTF(env, buff);
}

