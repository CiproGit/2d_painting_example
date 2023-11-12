#include "glwidget.h"
#include <QTimer>

GLWidget::GLWidget(helper::Helper *helper, QWidget *parent) : QOpenGLWidget(parent) {
	this->helper = helper;
	this->elapsed = 0;
	setFixedSize(200, 200);
	setAutoFillBackground(false);
}

GLWidget::~GLWidget() = default;

void GLWidget::paintEvent(QPaintEvent *event) {
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	this->helper->paint(&painter, event, elapsed);
	painter.end();
}

void GLWidget::animate() {
	this->elapsed = (this->elapsed + qobject_cast<QTimer *>(sender())->interval()) % 1000;
	update();
}
