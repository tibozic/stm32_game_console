#include <gui/screen_space_invaders_screen/screen_space_invadersView.hpp>

touchgfx::ScalableImage enemies[NUM_OF_ENEMIES];
int enemy_move_direction = MOVE_RIGHT;

bool invaders_game_over = false;
int enemies_killed = 0;

screen_space_invadersView::screen_space_invadersView()
{
	// Hide the reference enemy
	enemy1.setVisible(false);
	enemy1.invalidate();

	// hide the bullet
	bullet.setVisible(false);
	bullet.setXY(-1, -1);
	bullet.invalidate();

	lbl_game_over.setVisible(false);
	lbl_game_over.invalidate();

	btn_back.setVisible(false);
	btn_back.invalidate();

	lbl_lose.setVisible(false);
	lbl_lose.invalidate();

	lbl_win.setVisible(false);
	lbl_win.invalidate();

	enemies_killed = 0;

	enemy_move_direction = MOVE_RIGHT;

	// Initialize all the enemies
	int current_x = 0;
	int current_y = 0;
	int counter = 0;

	for(int i = 0; i < NUM_OF_ROWS_OF_ENEMIES; ++i) {
		current_x = 0;
		for(int j = 0; j < NUM_OF_ENEMIES_PER_ROW; ++j) {
			enemies[counter].setBitmap(touchgfx::Bitmap(BITMAP_SPACE_INVADERS_ENEMY_ID));
			enemies[counter].setPosition(current_x, current_y, 50, 52);
			enemies[counter].setScalingAlgorithm(touchgfx::ScalableImage::NEAREST_NEIGHBOR);
			enemies[counter].setVisible(true);
			add(enemies[counter]);
			enemies[counter].invalidate();

			current_x += enemy1.getWidth() + SPACE_BETWEEN_ENEMIES_X;
			counter++;
		}
		current_y += enemy1.getHeight() + SPACE_BETWEEN_ENEMIES_Y;
	}

	invaders_game_over = false;
}

void screen_space_invadersView::setupScreen()
{
    screen_space_invadersViewBase::setupScreen();
}

void screen_space_invadersView::tearDownScreen()
{
    screen_space_invadersViewBase::tearDownScreen();
}

void screen_space_invadersView::handleTickEvent()
{
	if( !invaders_game_over ) {
		check_bullet_hitbox();

		// move the bullet
		if( bullet.isVisible() ) {
			bullet.setY(bullet.getY() - BULLET_MOVE_SPEED);
			bullet.invalidate();

			if( bullet.getY()+bullet.getHeight() < 0 ) {
				bullet.setVisible(false);
				bullet.invalidate();
			}
		}

		// move the ship
		if( btn_left.getPressedState() && ship.getX() > 0 ) {
			ship.setX(ship.getX() - SHIP_MOVE_SPEED);
		}
		else if( btn_right.getPressedState() && ship.getX() + ship.getWidth() < SCREEN_WIDTH ) {
			ship.setX(ship.getX() + SHIP_MOVE_SPEED);
		}
		ship.getParent()->invalidate();

		// move all the enemies

		static int pixels_moved = 0;
		static int tick = 0;

		if( ++tick%10 == 0 ) {
			if( enemy_move_direction == MOVE_RIGHT ) {
				if( enemies[NUM_OF_ENEMIES_PER_ROW-1].getX() + enemies[NUM_OF_ENEMIES_PER_ROW].getWidth() < SCREEN_WIDTH ) {
					for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
						enemies[i].setX(enemies[i].getX() + ENEMY_MOVE_SPEED);
						enemies[i].invalidate();
					}
				} else {
					enemy_move_direction = MOVE_DOWN;
				}
			}
			else if( enemy_move_direction == MOVE_LEFT ) {
				if( enemies[0].getX() > 10 ) {
					for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
						enemies[i].setX(enemies[i].getX() - ENEMY_MOVE_SPEED);
						enemies[i].invalidate();
					}
				} else {
					enemy_move_direction = MOVE_DOWN;
				}
			}
			else if( enemy_move_direction == MOVE_DOWN ) {
				if( pixels_moved < enemies[0].getHeight()/2 ) {
					for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
						enemies[i].setY(enemies[i].getY() + ENEMY_MOVE_SPEED);
						enemies[i].invalidate();
						pixels_moved += ENEMY_MOVE_SPEED;
					}
				}
				else {
					pixels_moved = 0;
					if( enemies[NUM_OF_ENEMIES_PER_ROW-1].getX() + enemies[NUM_OF_ENEMIES_PER_ROW].getWidth() < SCREEN_WIDTH ) {
						enemy_move_direction = MOVE_RIGHT;
					}
					else {
						enemy_move_direction = MOVE_LEFT;
					}
				}
			}
		}

		check_game_over();
	}
	else {
		lbl_game_over.setVisible(true);
		lbl_game_over.invalidate();

		btn_back.setVisible(true);
		btn_back.invalidate();

		if( enemies_killed == NUM_OF_ENEMIES ) {
			lbl_win.setVisible(true);
			lbl_win.invalidate();
		}
		else {
			lbl_lose.setVisible(true);
			lbl_lose.invalidate();
		}
	}
}

void screen_space_invadersView::fire_bullet()
{
	if( !bullet.isVisible() )
	{
		bullet.setXY(ship.getX() + (ship.getWidth()/2 - bullet.getWidth()/2), ship.getY() - bullet.getHeight()/2);
		bullet.setVisible(true);
		bullet.invalidate();
	}
}

void screen_space_invadersView::check_bullet_hitbox()
{
	if( bullet.isVisible() ) {
		for(int i = 0; i < NUM_OF_ENEMIES; ++i ) {
			if( !enemies[i].isVisible() )
				continue;

			if( (bullet.getX() < enemies[i].getX()+enemies[i].getWidth()
				&& bullet.getX() > enemies[i].getX()
				&& bullet.getY() > enemies[i].getY()
				&& bullet.getY() < enemies[i].getY() + enemies[i].getHeight())
				|| (bullet.getX() + bullet.getWidth() < enemies[i].getX()+enemies[i].getWidth()
					&& bullet.getX() + bullet.getWidth() > enemies[i].getX()
					&& bullet.getY() > enemies[i].getY()
					&& bullet.getY() < enemies[i].getY() + enemies[i].getHeight())	)
			{
				// The bullet hit an enemy

				// remove the enemy
				enemies[i].setVisible(false);
				enemies[i].invalidate();

				// remove the bullet
				bullet.setVisible(false);
				bullet.setXY(-1, -1);
				bullet.invalidate();

				enemies_killed++;
				break;
			}

		}
	}
}

void screen_space_invadersView::check_game_over()
{
	// check that the player hasn't killed all the enemies
	invaders_game_over = true;
	for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
		if( enemies[i].isVisible()) {
			invaders_game_over = false;
			break;
		}
	}

	// check that the enemy hasn't collided with the player
	for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
		if( !enemies[i].isVisible() )
			continue;

		if( (ship.getX() < enemies[i].getX()+enemies[i].getWidth()
			&& ship.getX() > enemies[i].getX()
			&& ship.getY() + ship.getHeight()/2 > enemies[i].getY()
			&& ship.getY() + ship.getHeight()/2 < enemies[i].getY() + enemies[i].getHeight())
			|| (ship.getX() + ship.getWidth() < enemies[i].getX()+enemies[i].getWidth()
				&& ship.getX() + ship.getWidth() > enemies[i].getX()
				&& ship.getY() + ship.getHeight()/2 > enemies[i].getY()
				&& ship.getY() + ship.getHeight()/2 < enemies[i].getY() + enemies[i].getHeight())	)
		{
			// Enemy collided with the player
			invaders_game_over = true;
			return;
		}
	}

	// check that the enemy hasn't made it past the player
	for(int i = 0; i < NUM_OF_ENEMIES; ++i) {
		if( !enemies[i].isVisible() )
			continue;

		if( enemies[i].getY() > SCREEN_HEIGHT ) {
			// Enemy has gone past the player
			invaders_game_over = true;
			return;
		}
	}
}
