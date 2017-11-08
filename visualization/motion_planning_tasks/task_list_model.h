/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2017, Bielefeld University
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Bielefeld University nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

/* Author: Robert Haschke */

#pragma once

#include <moveit/macros/class_forward.h>
#include <moveit_task_constructor/TaskDescription.h>
#include <moveit_task_constructor/TaskStatistics.h>
#include <moveit_task_constructor/Solution.h>

#include <QAbstractItemModel>
#include <memory>

namespace moveit_rviz_plugin {

/** Base class to represent a single local or remote Task as a Qt model. */
class BaseTaskModel : public QAbstractItemModel {
public:
	BaseTaskModel(QObject *parent = nullptr) : QAbstractItemModel(parent) {}

	int columnCount(const QModelIndex &parent = QModelIndex()) const override { return 3; }
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	Qt::ItemFlags flags(const QModelIndex &index) const override;
};

class TaskListModelPrivate;
/** The TaskListModel maintains a list of multiple BaseTaskModels, local and/or remote.
 *
 *  This class is used e.g. by TaskDisplay to maintain the list of tasks published on
 *  a monitoring topic.
 *
 *  Local instances are created by insertLocalTask().
 *  Remote instances are discovered via processTaskMessage() / processSolutionMessage().
 */
class TaskListModel : public QAbstractItemModel {
	Q_OBJECT
	Q_DECLARE_PRIVATE(TaskListModel)
	TaskListModelPrivate* d_ptr;

public:
	TaskListModel(QObject *parent = nullptr);
	~TaskListModel();

	static QString horizontalHeader(int column);
	QVariant headerData(int section, Qt::Orientation orientation, int role) const override;

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override { return 3; }

	QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
	QModelIndex parent(const QModelIndex &index) const override;

	Qt::ItemFlags flags(const QModelIndex & index) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;

	bool removeRows(int row, int count, const QModelIndex &parent) override;

	/// process an incoming task description message - only call in Qt's main loop
	void processTaskDescriptionMessage(const moveit_task_constructor::TaskDescription &msg);
	/// process an incoming task description message - only call in Qt's main loop
	void processTaskStatisticsMessage(const moveit_task_constructor::TaskStatistics &msg);
	/// process an incoming solution message - only call in Qt's main loop
	void processSolutionMessage(const moveit_task_constructor::Solution &msg);

	/// retrieve TaskModel in given row
	BaseTaskModel* getTask(int row) const;

	/// insert a TaskModel into our list
	void insertTask(BaseTaskModel* model, int row = -1);
	bool removeTask(BaseTaskModel* model, bool disconnect_signals = true);

private:
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsAboutToBeInserted(QModelIndex,int,int))
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsInserted(QModelIndex,int,int))
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsAboutToBeRemoved(QModelIndex,int,int))
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsRemoved(QModelIndex,int,int))
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsAboutToBeMoved(QModelIndex,int,int,QModelIndex,int))
	Q_PRIVATE_SLOT(d_func(), void _q_sourceRowsMoved(QModelIndex,int,int,QModelIndex,int))

	Q_PRIVATE_SLOT(d_func(), void _q_sourceDataChanged(QModelIndex,QModelIndex,QVector<int>))
};
MOVEIT_CLASS_FORWARD(TaskListModel)
typedef std::weak_ptr<TaskListModel> TaskListModelWeakPtr;

}