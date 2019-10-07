//entête
#ifndef PAUSE_TASK_H
#define PAUSE_TASK_H

#include "Task.h"

class PauseTask : public Task {
	void process(ConsoleKeyReader::KeyEvents keyList) override;
	void render() override;
};


#endif // !PAUSE_TASK_H
