/*
 * Copyright (C) 2006 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "jni.h"

extern int registerCoreLibrariesJni(JNIEnv* env);
extern int registerJniHelp(JNIEnv* env);

/*
 * Register all methods for system classes.
 */
int jniRegisterSystemMethods(JNIEnv* env)
{
    // We initialize JNIHelp.c first so that the core libraries can safely rely on it.
    return registerJniHelp(env) != -1 && registerCoreLibrariesJni(env) != -1;
}
