#include <pebble.h>

Window *window;
TextLayer *text_layer;

/*
char *alphabet[] = {
	"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", 
	"m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"
};

static char buffer[] = "Our variable is 0";
	snprintf(buffer, sizeof(buffer), "Our variable is %d", our_variable);
	text_layer_set_text(text_layer, buffer);
*/












void select_click_handler(ClickRecognizerRef recognizer, void *context) {
	
}

void up_click_handler(ClickRecognizerRef recognizer, void *context) {

}

void down_click_handler(ClickRecognizerRef recognizer, void *context) {

}













/*
Don't worry about the code below here
*/
void click_config_provider(void *context) {
	window_single_click_subscribe(BUTTON_ID_SELECT, select_click_handler);
	window_single_click_subscribe(BUTTON_ID_UP, up_click_handler);
	window_single_click_subscribe(BUTTON_ID_DOWN, down_click_handler);
}

void window_load(Window *window) {
	Layer *window_layer = window_get_root_layer(window);
	GRect bounds = layer_get_bounds(window_layer);

	text_layer = text_layer_create(GRect(0, 72, bounds.size.w, 20));
	text_layer_set_text(text_layer, "Press a button");
	text_layer_set_text_alignment(text_layer, GTextAlignmentCenter);
	layer_add_child(window_layer, text_layer_get_layer(text_layer));
}

void window_unload(Window *window) {
	text_layer_destroy(text_layer);
}

void init() {
	window = window_create();
	window_set_click_config_provider(window, click_config_provider);
	window_set_window_handlers(window, (WindowHandlers) {
		.load = window_load,
		.unload = window_unload,
	});
	const bool animated = true;
	window_stack_push(window, animated);
}

void deinit() {
	window_destroy(window);
}

int main() {
	init();
	app_event_loop();
	deinit();
}