#include <gui/screen_tictactoe_game_screen/screen_tictactoe_gameView.hpp>

char board[3][3];
bool turn = true; // true -> player 1, false -> player2
short turn_number = 0;
bool game_over = false;
short result = 0;

screen_tictactoe_gameView::screen_tictactoe_gameView()
{

	// initialize the board to empty
	for(short i = 0; i < 3; ++i) {
		for(short j = 0; j < 3; ++j) {
			board[i][j] = 0;
		}
	}

	game_over = false;
	lbl_game_over.setVisible(false);
	lbl_game_over.invalidate();

	box_background.setVisible(false);
	box_background.invalidate();

	lbl_result.setVisible(false);
	lbl_result.invalidate();

	btn_back.setVisible(false);
	btn_back.invalidate();

	turn_number = 0;

	turn = true;
}

void screen_tictactoe_gameView::setupScreen()
{
    screen_tictactoe_gameViewBase::setupScreen();
}

void screen_tictactoe_gameView::tearDownScreen()
{
    screen_tictactoe_gameViewBase::tearDownScreen();
}

void screen_tictactoe_gameView::pos1_clicked() {
	if( !game_over && board[0][0] == 0 ) {
		if( turn ) {
			board[0][0] = 'X';
			pos1_cross.setVisible(true);
			pos1_cross.invalidate();
		} else {
			board[0][0] = 'O';
			pos1_circle.setVisible(true);
			pos1_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(0, 0);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos2_clicked() {
	if( !game_over && board[0][1] == 0 ) {
		if( turn ) {
			board[0][1] = 'X';
			pos2_cross.setVisible(true);
			pos2_cross.invalidate();
		} else {
			board[0][1] = 'O';
			pos2_circle.setVisible(true);
			pos2_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(0, 1);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos3_clicked() {
	if( !game_over && board[0][2] == 0 ) {
		if( turn ) {
			board[0][2] = 'X';
			pos3_cross.setVisible(true);
			pos3_cross.invalidate();
		} else {
			board[0][2] = 'O';
			pos3_circle.setVisible(true);
			pos3_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(0, 2);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos4_clicked() {
	if( !game_over && board[1][0] == 0 ) {
		if( turn ) {
			board[1][0] = 'X';
			pos4_cross.setVisible(true);
			pos4_cross.invalidate();
		} else {
			board[1][0] = 'O';
			pos4_circle.setVisible(true);
			pos4_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(1, 0);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos5_clicked() {
	if( !game_over && board[1][1] == 0 ) {
		if( turn ) {
			board[1][1] = 'X';
			pos5_cross.setVisible(true);
			pos5_cross.invalidate();
		} else {
			board[1][1] = 'O';
			pos5_circle.setVisible(true);
			pos5_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(1, 1);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos6_clicked() {
	if( !game_over && board[1][2] == 0 ) {
		if( turn ) {
			board[1][2] = 'X';
			pos6_cross.setVisible(true);
			pos6_cross.invalidate();
		} else {
			board[1][2] = 'O';
			pos6_circle.setVisible(true);
			pos6_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(1, 2);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos7_clicked() {
	if( !game_over && board[2][0] == 0 ) {
		if( turn ) {
			board[2][0] = 'X';
			pos7_cross.setVisible(true);
			pos7_cross.invalidate();
		} else {
			board[2][0] = 'O';
			pos7_circle.setVisible(true);
			pos7_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(2, 0);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos8_clicked() {
	if( !game_over && board[2][1] == 0 ) {
		if( turn ) {
			board[2][1] = 'X';
			pos8_cross.setVisible(true);
			pos8_cross.invalidate();
		} else {
			board[2][1] = 'O';
			pos8_circle.setVisible(true);
			pos8_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(2, 1);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::pos9_clicked() {
	if( !game_over && board[2][2] == 0 ) {
		if( turn ) {
			board[2][2] = 'X';
			pos9_cross.setVisible(true);
			pos9_cross.invalidate();
		} else {
			board[2][2] = 'O';
			pos9_circle.setVisible(true);
			pos9_circle.invalidate();
		}

		turn_number++;

		short temp_result = is_game_over(2, 2);

		if( temp_result != 0 ) {
			game_over = true;
			result = temp_result;
			return;
		}

		turn = !turn;
	}
}

void screen_tictactoe_gameView::handleTickEvent() {
	if( game_over ) {
		btn_back.setVisible(true);
		btn_back.invalidate();

		box_background.setVisible(true);
		box_background.invalidate();

		lbl_game_over.setVisible(true);
		lbl_game_over.invalidate();

		lbl_result.setVisible(true);

		if( result == 1 )
			Unicode::snprintf(lbl_resultBuffer, LBL_RESULT_SIZE, "Player 1 wins");
		else if( result == 2 )
			Unicode::snprintf(lbl_resultBuffer, LBL_RESULT_SIZE, "Player 2 wins");
		else if( result == 3 )
			Unicode::snprintf(lbl_resultBuffer, LBL_RESULT_SIZE, "Tie");

		lbl_result.invalidate();
	}
	else {
		if( turn )
			Unicode::snprintf(lbl_turnBuffer, LBL_TURN_SIZE, "1");
		else
			Unicode::snprintf(lbl_turnBuffer, LBL_TURN_SIZE, "2");

		lbl_turn.invalidate();
	}
}

short screen_tictactoe_gameView::is_game_over(int x, int y) {
	// 0 -> game isn't over
	// 1 -> player 1 wins
	// 2 -> player 2 wins
	// 3 -> tie

	char symbol;

	if(turn)
		symbol = 'X';
	else
		symbol = 'O';

    //check col
    for(short i = 0; i < 3; i++){
        if(board[x][i] != symbol)
            break;
        if(i == 3-1){
            if( turn )
            	return 1;
            else
            	return 2;
        }
    }

    //check row
    for(int i = 0; i < 3; i++){
        if(board[i][y] != symbol)
            break;
        if(i == 3-1){
            if( turn )
            	return 1;
            else
            	return 2;
        }
    }

    //check diagonal
    if(x == y){
        //we're on a diagonal
        for(int i = 0; i < 3; i++){
            if(board[i][i] != symbol)
                break;
            if(i == 3-1){
                if( turn )
                	return 1;
                else
                	return 2;
            }
        }
    }

    //check anti diag
    if(x + y == 3-1){
        for(int i = 0; i < 3; i++){
            if(board[i][(3-1)-i] != symbol)
                break;
            if(i == 3-1){
                if( turn )
                	return 1;
                else
                	return 2;
            }
        }
    }

	if( turn_number == 9 )
		return 3;

	return 0;
}
