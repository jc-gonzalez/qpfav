/******************************************************************************
 * File:    tasksmodel.cpp
 *          This file is part of QLA Processing Framework
 *
 * Domain:  QPF.libQPF.tasksmodel
 *
 * Version:  2.0
 *
 * Date:    2015/07/01
 *
 * Author:   J C Gonzalez
 *
 * Copyright (C) 2015-2018 Euclid SOC Team @ ESAC
 *_____________________________________________________________________________
 *
 * Topic: General Information
 *
 * Purpose:
 *   Provides object implementation for some declarations
 *
 * Created by:
 *   J C Gonzalez
 *
 * Status:
 *   Prototype
 *
 * Dependencies:
 *   none
 *
 * Files read / modified:
 *   none
 *
 * History:
 *   See <Changelog>
 *
 * About: License Conditions
 *   See <License>
 *
 ******************************************************************************/

#include "tasksmodel.h"

namespace QPF {

TasksModel::TasksModel()
{
    defineQuery("SELECT "
                "id as ID, "
                "t.task_data#>>'{State,StartedAt}' AS start, "
                "t.task_data#>>'{State,FinishedAt}' AS finish, "
                //"t.task_data#>>'{Info,TaskName}' AS name, "
                "t.task_data#>>'{Info,MainInput}' AS name, "
                "t.task_data#>>'{Info,Agent}' AS agent, "
                "t.task_path AS proc, "
                "tt.status_desc AS status, "
                "t.task_progress AS progress, "
                "t.task_data#>>'{State,ExitCode}' AS exit_code, "
                "t.task_data AS task_data "
                "FROM tasks_info t "
                "INNER JOIN task_status tt "
                //"      ON t.task_data#>>'{State,TaskStatus}' = tt.task_status_id::text "
                "      ON t.task_status_id = tt.task_status_id "
                "ORDER BY id;");

    defineHeaders({"ID", "Started at", "Finished at",
                "Main Input Product", "Agent", "Proc.Element",
                "Status", "Progress", "Exit Code", "Task Info"});


    ColumnPalette statusPalette;
    statusPalette["SCHEDULED"] = FgBgColors(QColor(Qt::gray),  QColor(255, 255, 255, 0));
    statusPalette["RUNNING"]   = FgBgColors(QColor(Qt::cyan),  QColor(255, 255, 255, 0));
    statusPalette["FINISHED"]  = FgBgColors(QColor(Qt::black), QColor(Qt::green));
    statusPalette["PAUSED"]    = FgBgColors(QColor(Qt::blue),  QColor(Qt::lightGray));
    statusPalette["FAILED"]    = FgBgColors(QColor(Qt::white), QColor(Qt::red));
    statusPalette["STOPPED"]   = FgBgColors(QColor(Qt::black), QColor(Qt::yellow));
    statusPalette["ABORTED"]   = FgBgColors(QColor(Qt::black), QColor(Qt::darkYellow));
    statusPalette["ARCHIVED"]  = FgBgColors(QColor(Qt::black), QColor(Qt::gray));
    statusPalette["UNKNOWN"]   = FgBgColors(QColor(Qt::red),   QColor(Qt::darkRed));

    TablePalette  tblPalette;
    tblPalette[6] = statusPalette;

    defineTablePalette(tblPalette);

    setFullUpdate(true);

    refresh();
}

}
