#include "widget.h"
#include <QTimer>

Widget::Widget(helper::Helper *helper, QWidget *parent) : QWidget(parent) {
	this->helper = helper;
	this->elapsed = 0;
	setFixedSize(200, 200);
}

Widget::~Widget() = default;

void Widget::paintEvent(QPaintEvent *event) {
	QPainter painter;
	painter.begin(this);
	painter.setRenderHint(QPainter::Antialiasing);
	this->helper->paint(&painter, event, elapsed);
	painter.end();
}

void Widget::animate() {
	this->elapsed = (this->elapsed + qobject_cast<QTimer *>(sender())->interval()) % 1000;
	update();
}
