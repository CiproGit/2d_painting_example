#include "helper.h"

namespace helper {
	Helper::Helper() {
		QLinearGradient gradient(QPointF(50, -20), QPointF(80, 20));
		gradient.setColorAt(0.0, Qt::white);
		gradient.setColorAt(1.0, QColor(0xa6, 0xce, 0x39));

		this->background = QBrush(QColor(64,32,64));
		this->circle_brush = QBrush(gradient);
		this->circle_pen = QPen(Qt::black);
		this->circle_pen.setWidth(1);
		this->text_pen = QPen(Qt::white);
		this->text_font.setPixelSize(50);
	}

	helper::Helper::~Helper() = default;

	void helper::Helper::paint(QPainter *painter, QPaintEvent *event, int elapsed) {
		painter->fillRect(event->rect(), this->background);
		painter->translate(100, 100);

		painter->save();
		painter->setBrush(this->circle_brush);
		painter->setPen(this->circle_pen);
		painter->rotate(elapsed * 0.03);

		qreal r = elapsed / 1000;
		int n = 30;

		for (int i = 0; i < n; i++) {
			painter->rotate(30);
			qreal factor = (i + r) / n;
			qreal radius = 120 * factor;
			qreal circle_radius = 1 + factor * 20;
			painter->drawEllipse(QRectF(radius, -circle_radius, circle_radius * 2, circle_radius * 2));
		}
		painter->restore();

		painter->setPen(this->text_pen);
		painter->setFont(this->text_font);
		painter->drawText(QRect(-50, -50, 100, 100), Qt::AlignCenter, QStringLiteral("Qt"));
	}
} // namespace helper
