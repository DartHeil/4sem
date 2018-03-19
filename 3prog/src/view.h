#include <Graphics.hpp>

using namespace sf;

View view;

View get_xy_for_view(float x, float y)
{
	view.setCenter(x+100, y);
	return view;
}
