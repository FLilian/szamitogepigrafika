#ifndef SCREEN_MESSAGE_H
#define SCREEN_MESSAGE_H


typedef enum {
	NONE = -1, 
	HELP = 10, 
} ShownScreenMessage;

/**
 * Toggles the visiblity of the help menu if no other message displayed.
 */
void HelpMenu(int key, ShownScreenMessage* shownMessage);

/**
 * Renders the given texture message to the screen.
 */
void renderScreenMessage(Texture shownScreenMessageTexture);
							  
#endif /* SCREEN_MESSAGE_H */
