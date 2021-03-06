/*
 * Copyright (c) 2020 Huawei Technologies Co.,Ltd.
 *
 * openGauss is licensed under Mulan PSL v2.
 * You can use this software according to the terms and conditions of the Mulan PSL v2.
 * You may obtain a copy of Mulan PSL v2 at:
 *
 *          http://license.coscl.org.cn/MulanPSL2
 *
 * THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
 * EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
 * MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
 * See the Mulan PSL v2 for more details.
 * -------------------------------------------------------------------------
 *
 * mot_fdw.h
 *    MOT Foreign Data Wrapper interfaces used by the envelop during
 *    initialization, recovery, etc.
 *
 * IDENTIFICATION
 *    src/include/storage/mot/mot_fdw.h
 *
 * -------------------------------------------------------------------------
 */

#ifndef MOT_FDW_H
#define MOT_FDW_H

/** @brief Initializes MOT engine. */
extern void InitMOT();

/** @brief Shutdown the MOT engine. */
extern void TermMOT();

/**
 * @brief Initializes the thread level and recovers the data from MOT checkpoint.
 * Should be called before XLOG recovery in the envelop.
 */
extern void MOTRecover();

/**
 * @brief Cleans up the resources and finishes the recovery.
 * Should be called at the end of recovery in the envelop.
 */
extern void MOTRecoveryDone();

/**
 * @brief Initializes the thread level resources for MOT redo recovery.
 * If the MOT redo recovery is done in a separate thread other than the main thread which calls MOTRecover(),
 * this API should be called to initialize the thread before performing redo recovery.
 */
extern void MOTBeginRedoRecovery();

/**
 * @brief Cleans up the thread level resources. Used with MOTBeginRedoRecovery().
 * Should be called at the end of the thread after finishing redo recovery.
 */
extern void MOTEndRedoRecovery();

/**
 * The following helpers APIs are used by base backup to fetch and send the MOT checkpoint files.
 */
extern void MOTCheckpointFetchLock();
extern void MOTCheckpointFetchUnlock();
extern char* MOTCheckpointFetchDirName();
extern char* MOTCheckpointFetchWorkingDir();
extern uint64_t MOTCheckpointGetId();

#endif  // MOT_FDW_H
