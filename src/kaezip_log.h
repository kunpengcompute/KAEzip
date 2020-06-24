/*
 * Copyright (C) 2019. Huawei Technologies Co., Ltd. All rights reserved.
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the zlib License. 
 * You may obtain a copy of the License at
 * 
 *     https://www.zlib.net/zlib_license.html
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * zlib License for more details.
 */

/*****************************************************************************
 * @file kaezip_log.h
 *
 * This file provides the log funtion;
 *
 *****************************************************************************/

#ifndef KAEZIP_LOG_H
#define KAEZIP_LOG_H
#include <sys/file.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <pthread.h>

#define LOG_LEVEL_CONFIG      KAE_NONE
#define KAE_DEBUG_FILE_PATH   "/var/log/kaezip.log"
#define KAE_DEBUG_FILE_PATH_OLD "/var/log/kaezip.log.old"
#define KAE_LOG_MAX_SIZE 209715200

extern FILE *g_kae_debug_log_file;
extern pthread_mutex_t g_debug_file_mutex;
extern const char *g_log_level[];
extern int g_kae_log_level;

enum KAE_LOG_LEVEL {
    KAE_NONE = 0,
    KAE_ERROR,
    KAE_WARNING,
    KAE_INFO,
    KAE_DEBUG,
};

void ENGINE_LOG_LIMIT(int level, int times, int limit, const char *fmt, ...);

#define CRYPTO(LEVEL, fmt, args...)                                                                     \
    do {                                                                                                \
        if (LEVEL > g_kae_log_level) {                                                                  \
            break;                                                                                      \
        }                                                                                               \
        struct tm *log_tm_p = NULL;                                                                     \
        time_t timep = time((time_t *)NULL);                                                            \
        log_tm_p = localtime(&timep);                                                                   \
        flock(g_kae_debug_log_file->_fileno, LOCK_EX);                                                  \
        pthread_mutex_lock(&g_debug_file_mutex);                                                        \
        fseek(g_kae_debug_log_file, 0, SEEK_END);                                                       \
        if (log_tm_p != NULL) {                                                                         \
            fprintf(g_kae_debug_log_file, "[%4d-%02d-%02d %02d:%02d:%02d][%s][%s:%d:%s()] " fmt "\n",   \
                (1900 + log_tm_p->tm_year), (1 + log_tm_p->tm_mon), log_tm_p->tm_mday,                  \
                log_tm_p->tm_hour, log_tm_p->tm_min, log_tm_p->tm_sec,                                  \
                g_log_level[LEVEL], __FILE__, __LINE__, __func__, ##args);                              \
        } else {                                                                                        \
            fprintf(g_kae_debug_log_file, "[%s][%s:%d:%s()] " fmt "\n",                                 \
                g_log_level[LEVEL], __FILE__, __LINE__, __func__, ##args);                              \
        }                                                                                               \
        if (ftell(g_kae_debug_log_file) > KAE_LOG_MAX_SIZE) {                                           \
            kae_save_log(g_kae_debug_log_file);                                                         \
            ftruncate(g_kae_debug_log_file->_fileno, 0);                                                \
            fseek(g_kae_debug_log_file, 0, SEEK_SET);                                                   \
        }                                                                                               \
            pthread_mutex_unlock(&g_debug_file_mutex);                                                  \
            flock(g_kae_debug_log_file->_fileno, LOCK_UN);                                              \
    } while (0)

#define US_ERR(fmt, args...)          CRYPTO(KAE_ERROR, fmt, ##args)
#define US_WARN(fmt, args...)         CRYPTO(KAE_WARNING, fmt, ##args)
#define US_INFO(fmt, args...)         CRYPTO(KAE_INFO, fmt, ##args)
#define US_DEBUG(fmt, args...)        CRYPTO(KAE_DEBUG, fmt, ##args)
#define US_WARN_LIMIT(fmt, args...)   ENGINE_LOG_LIMIT(KAE_WARNING, 3, 30, fmt, ##args)
#define US_ERR_LIMIT(fmt, args...)    ENGINE_LOG_LIMIT(KAE_ERROR, 3, 30, fmt, ##args)
#define US_INFO_LIMIT(fmt, args...)   ENGINE_LOG_LIMIT(KAE_INFO, 3, 30, fmt, ##args)
#define US_DEBUG_LIMIT(fmt, args...)  ENGINE_LOG_LIMIT(KAE_DEBUG, 3, 30, fmt, ##args)

void kae_debug_init_log();
void kae_debug_close_log();
void kae_save_log(FILE *src);

#endif
