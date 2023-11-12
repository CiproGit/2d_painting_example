#ifndef GLWIDGET_H
#define GLWIDGET_H

#include "helper.h"
#include <QOpenGLWidget>

class GLWidget : public QOpenGLWidget {
	Q_OBJECT

private:
	helper::Helper *helper;
	int elapsed;

protected:
	void paintEvent(QPaintEvent *event);

public:
	GLWidget(helper::Helper *helper, QWidget *parent = nullptr);
	virtual ~GLWidget();

public slots:
	void animate();
};

#endif // GLWIDGET_H
