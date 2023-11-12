#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "helper.h"
#include <QWidget>

class Main_window : public QWidget {
	Q_OBJECT

private:
	helper::Helper helper;

public:
	Main_window();
	virtual ~Main_window();
};

#endif // MAIN_WINDOW_H
