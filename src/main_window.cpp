#include "main_window.h"
#include "widget.h"
#include "glwidget.h"
#include <QLabel>
#include <QGridLayout>
#include <QTimer>

Main_window::Main_window() {
	setWindowTitle(tr("2d painting on native and OpenGL widgets"));

	Widget *native = new Widget(&(this->helper), this);
	GLWidget *opengl = new GLWidget(&(this->helper), this);

	QLabel *native_label = new QLabel(tr("Native"));
	native_label->setAlignment(Qt::AlignHCenter);

	QLabel *opengl_label = new QLabel(tr("OpenGL"));
	opengl_label->setAlignment(Qt::AlignHCenter);

	QGridLayout *layout = new QGridLayout;
	layout->addWidget(native, 0, 0);
	layout->addWidget(opengl, 0, 1);
	layout->addWidget(native_label, 1, 0);
	layout->addWidget(opengl_label, 1, 1);
	setLayout(layout);

	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), native, SLOT(animate()));
	connect(timer, SIGNAL(timeout()), opengl, SLOT(animate()));
	timer->start(50);
}

Main_window::~Main_window() = default;
