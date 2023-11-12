#ifndef WIDGET_H
#define WIDGET_H

#include "helper.h"
#include <QWidget>

class Widget : public QWidget {
	Q_OBJECT

private:
	helper::Helper *helper;
	int elapsed;

protected:
	void paintEvent(QPaintEvent *event);

public:
	Widget(helper::Helper *helper, QWidget *parent = nullptr);
	virtual ~Widget();

public slots:
	void animate();
};

#endif // WIDGET_H
