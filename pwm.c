#include <X11/Xlib.h>
#include <stdio.h>

int main () {
	Display *dpy;
	dpy = XOpenDisplay(NULL);
	Window root;
	root = XDefaultRootWindow(dpy);
	
	int screen_number = XDefaultScreen(dpy);
	int connect_number = XConnectionNumber(dpy);
	int depth = XDefaultDepth(dpy, screen_number);
	int *depth_list = XListDepths(dpy, screen_number, &depth);
	Colormap colormap = XDefaultColormap(dpy, screen_number);
	unsigned long black_pixel = XBlackPixel(dpy, screen_number);
	unsigned long white_pixel = XBlackPixel(dpy, screen_number);
	GC gc = XDefaultGC(dpy, screen_number);
	Visual *vis = XDefaultVisual(dpy, screen_number);
	int dpycells = XDisplayCells(dpy, screen_number);
	int dpyplanes = XDisplayPlanes(dpy, screen_number);
	char *dpystring = XDisplayString(dpy);
	long ex_request_size = XExtendedMaxRequestSize(dpy);
	long request_size = XMaxRequestSize(dpy);
	unsigned long last_request = XLastKnownRequestProcessed(dpy);
	unsigned long next_request = XNextRequest(dpy);

	printf("You have %d screen/screens\n", XScreenCount(dpy));
	printf("Your connection number is %d\n", connect_number);
	printf("Your depth is %d\n", depth);
	for (int i = 0; i < depth; i++) {
		printf("Depth list %d\n", depth_list[i]);
	}
	XFree(depth_list);
	printf("Display cells %d\n", dpycells);
	printf("Display planes %d\n", dpyplanes);
	printf("Display string %s\n", dpystring);	
	printf("Request size %ld\n", ex_request_size);
	printf("Request size %ld\n", request_size);
	printf("Last request %lu\n", last_request);
	printf("Next request %lu\n", next_request);

	XCloseDisplay(dpy);

	return 0;
}
