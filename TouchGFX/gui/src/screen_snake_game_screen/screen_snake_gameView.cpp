#include <gui/screen_snake_game_screen/screen_snake_gameView.hpp>

bool game_started = false;
short snake_direction = SNAKE_DOWN;
int snake_length = 1;

snake_piece *head = NULL;
snake_piece *tail = NULL;

touchgfx::Box snake_pixels[MAX_SNAKE_PIECES];

screen_snake_gameView::screen_snake_gameView()
{

}

void screen_snake_gameView::setupScreen()
{
    screen_snake_gameViewBase::setupScreen();
}

void screen_snake_gameView::tearDownScreen()
{
    screen_snake_gameViewBase::tearDownScreen();
}

void screen_snake_gameView::game_snake_start()
{
	// first hide the button
	btn_snake_start.setVisible(false);
	btn_snake_start.invalidate();

	btn_back.setVisible(false);
	btn_back.invalidate();

	snake_head.setVisible(false);
	snake_head.invalidate();

	lbl_game_over.setVisible(false);
	lbl_game_over.invalidate();

	snake_pixels[0] = Box();

	if( head == NULL )
		head = (snake_piece*)malloc(sizeof(snake_piece));

	if( head == NULL ) {
		error();
		return;
	}

	head->pixel = &snake_pixels[0];

	head->pixel->setPosition(10, 20, 10, 10);
	head->pixel->setColor(touchgfx::Color::getColorFromRGB(0, 255, 50));
	add(*head->pixel);
	head->pixel->getParent()->invalidate();

	head->next = NULL;
	head->prev = NULL;
	head->old_x = 0;
	head->old_y = 0;

	tail = head;

	snake_direction = SNAKE_DOWN;

	snake_length = 1;

	game_started = true;

	// game_snake_loop();
}

void screen_snake_gameView::handleTickEvent() {
	static int tick = 0;

	if( game_started )
	{
		if( ++tick % SNAKE_SPEED == 0 )
		{
			// check if the head is out of bounds
			if( head->pixel->getX() > SCREEN_WIDTH || head->pixel->getX() < 0 ||
				head->pixel->getY() > SCREEN_HEIGHT || head->pixel->getY() < 0)
			{
				game_started = false;
			}

			// check if the snake ate itself
			snake_piece *snake_part = head->next;
			while( snake_part != NULL )
			{
				if( snake_part->pixel->getX() == head->pixel->getX() && snake_part->pixel->getY() == head->pixel->getY() ) {
					game_started = false;
					tick = 0;
					break;
				}

				snake_part = snake_part->next;
			}


			// check if the snake ate food
			snake_part = head;

			while( snake_part != NULL )
			{
				if( snake_part->pixel->getX() == food.getX() && snake_part->pixel->getY() == food.getY() ) {
					snake_length++;

					if( snake_length == MAX_SNAKE_PIECES-1 ) {
						// TODO: You win
						game_started = false;
					}

					// extend the snake

					snake_piece *new_piece = (snake_piece*)malloc(sizeof(snake_piece));

					if( new_piece == NULL ) {
						error();
						return;
					}

					snake_pixels[snake_length-1] = Box();
					new_piece->pixel = &snake_pixels[snake_length-1];
					new_piece->pixel->setPosition(0, 0, PIXEL_WIDTH, PIXEL_HEIGHT);
					// new_piece->pixel->setPosition(new_piece->prev->old_x, new_piece->prev->old_y, PIXEL_WIDTH, PIXEL_HEIGHT);
					new_piece->pixel->setColor(touchgfx::Color::getColorFromRGB(255, 130, 0));
					new_piece->pixel->setVisible(true);
					add(*new_piece->pixel);
					new_piece->pixel->getParent()->invalidate();

					tail->next = new_piece;
					new_piece->prev = tail;
					new_piece->next = NULL;
					new_piece->old_x = 0;
					new_piece->old_y = 0;
					tail = new_piece;

					// generate new food
					int food_new_x = pseudo_random(tick) % 480;
					int food_new_y = pseudo_random2(tick) % 272;

					food_new_x = food_new_x - (food_new_x % 10);
					food_new_y = food_new_y - (food_new_y % 10);

					food.setXY(food_new_x, food_new_y);
					food.invalidate();

					Unicode::snprintf(lbl_score_valBuffer, LBL_SCORE_VAL_SIZE, "%d", snake_length);
					lbl_score_val.invalidate();

					break;
				}

				snake_part = snake_part->next;
			}

			// move the snake
			if( snake_direction == SNAKE_RIGHT )
			{
				head->old_x = head->pixel->getX();
				head->old_y = head->pixel->getY();
				head->pixel->setXY(head->old_x+(SNAKE_MOVE), head->old_y);
				head->pixel->getParent()->invalidate();

				snake_piece *piece = head->next;
				while( piece != NULL )
				{
					piece->old_x = piece->pixel->getX();
					piece->old_y = piece->pixel->getY();
					piece->pixel->setXY(piece->prev->old_x, piece->prev->old_y);
					piece->pixel->getParent()->invalidate();
					piece = piece->next;
				}
			}
			else if( snake_direction == SNAKE_LEFT )
			{
				head->old_x = head->pixel->getX();
				head->old_y = head->pixel->getY();
				head->pixel->setXY(head->old_x-(SNAKE_MOVE), head->old_y);
				head->pixel->getParent()->invalidate();

				snake_piece *piece = head->next;
				while( piece != NULL )
				{
					piece->old_x = piece->pixel->getX();
					piece->old_y = piece->pixel->getY();
					piece->pixel->setXY(piece->prev->old_x, piece->prev->old_y);
					piece->pixel->getParent()->invalidate();
					piece = piece->next;
				}
			}
			else if( snake_direction == SNAKE_UP )
			{
				head->old_x = head->pixel->getX();
				head->old_y = head->pixel->getY();
				head->pixel->setXY(head->old_x, head->old_y-(SNAKE_MOVE));
				head->pixel->getParent()->invalidate();

				snake_piece *piece = head->next;
				while( piece != NULL )
				{
					piece->old_x = piece->pixel->getX();
					piece->old_y = piece->pixel->getY();
					piece->pixel->setXY(piece->prev->old_x, piece->prev->old_y);
					piece->pixel->getParent()->invalidate();
					piece = piece->next;
				}
			}
			else if( snake_direction == SNAKE_DOWN )
			{
				head->old_x = head->pixel->getX();
				head->old_y = head->pixel->getY();
				head->pixel->setXY(head->old_x, head->old_y+(SNAKE_MOVE));
				head->pixel->getParent()->invalidate();

				snake_piece *piece = head->next;
				while( piece != NULL )
				{
					piece->old_x = piece->pixel->getX();
					piece->old_y = piece->pixel->getY();
					piece->pixel->setXY(piece->prev->old_x, piece->prev->old_y);
					// piece->pixel->setXY(head->old_x, head->old_y+(SNAKE_MOVE));
					piece->pixel->getParent()->invalidate();
					piece = piece->next;
				}
			}

			head->pixel->getParent()->invalidate();
		}
	}
	else {
		snake_piece *old = NULL;


		if( head != NULL ) {
			old = head->next;
		}

		while( old != NULL ) {
			old->pixel->setXY(-1, -1);
			old->pixel->setVisible(false);
			old->pixel->getParent()->invalidate();

			old = old->next;

			if( old != NULL ) {
				free(old->prev);
				old->prev = NULL;
			}
			else if (head != tail ) {
				free(tail);
			}
		}



		if( head != NULL ) {
			tail = head;
			head->next = NULL;
			head->pixel->setXY(20, 50);
			head->pixel->getParent()->invalidate();
			snake_length = 1;
		}


		/*
		snake_piece *temp = head->next;
		while( temp != NULL ) {

			temp->pixel->setXY(-1, -1);
			temp->pixel->getParent()->invalidate();

			temp = temp->next;
			free(temp->prev);
			temp->prev = NULL;
		}

		tail = head;
		head->next = NULL;
		head->pixel->setXY(20, 50);
		head->pixel->getParent()->invalidate();
		snake_length = 1;
		*/

		btn_back.setVisible(true);
		btn_back.invalidate();

		if( tick > 0 ) {
			tick = 0;
			lbl_game_over.setVisible(true);
			lbl_game_over.invalidate();
		}
	}
}

void screen_snake_gameView::error() {
	touchgfx::Box error_square = Box();
	error_square.setPosition(0, 0, 480, 272);
	error_square.setColor(touchgfx::Color::getColorFromRGB(255, 0, 0));
	add(error_square);
	error_square.getParent()->invalidate();
}

void screen_snake_gameView::change_direction_up() {
	snake_direction = SNAKE_UP;
}

void screen_snake_gameView::change_direction_down() {
	snake_direction = SNAKE_DOWN;
}

void screen_snake_gameView::change_direction_left() {
	snake_direction = SNAKE_LEFT;
}

void screen_snake_gameView::change_direction_right() {
	snake_direction = SNAKE_RIGHT;
}

int screen_snake_gameView::pseudo_random(int tick) {
	return (3*snake_length + SNAKE_SPEED*3*tick + 3*tail->pixel->getX() * 3*tail->pixel->getY());
}

int screen_snake_gameView::pseudo_random2(int tick) {
	return (7*snake_length + SNAKE_SPEED*7*tick + 7*tail->pixel->getX() * 7*tail->pixel->getY());
}

