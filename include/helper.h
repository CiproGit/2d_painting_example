#ifndef HELPER_H
#define HELPER_H

#include <QPainter>
#include <QPaintEvent>
#include <QBrush>
#include <QFont>
#include <QPen>

namespace helper {
	class Helper {
	private:
		QBrush background;
		QBrush circle_brush;
		QFont text_font;
		QPen circle_pen;
		QPen text_pen;

	public:
		Helper();
		virtual ~Helper();
		void paint(QPainter *painter, QPaintEvent *event, int elapsed);
	};
} // namespace helper

#endif // HELPER_H
