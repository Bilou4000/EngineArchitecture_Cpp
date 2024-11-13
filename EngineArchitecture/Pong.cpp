#include "Pong.h"

Pong::Pong() : Scene()
{
}

void Pong::Start(Renderer* pRenderer)
{
	mRenderer = pRenderer;

	Vector2 winDimension = mWindow->GetDimensions();
	mBall = { { winDimension.y / 2 - mBallSize / 2, winDimension.y / 2 - mBallSize / 2 }, { mBallSize, mBallSize } };
	mPaddleRight = { { 10, winDimension.y / 2 - mPaddleHeight / 2 }, { mPaddleWidth, mPaddleHeight } };
	mPaddleLeft = { { winDimension.x - mPaddleWidth - 10, winDimension.y / 2 - mPaddleHeight / 2 }, { mPaddleWidth, mPaddleHeight } };
}

void Pong::Update(float deltaTime)
{


	//player paddle movement
	if(mIsGoingUp && (mPaddleRight.position.y > 0))
	{
		mPaddleRight.position.y -= mPaddleSpeed * Time::deltaTime;
	}
	if(mIsGoingDown && (mPaddleRight.position.y < mWindow->GetDimensions().y - mPaddleHeight ))
	{
		mPaddleRight.position.y += mPaddleSpeed * Time::deltaTime;
	}

	//ai paddle movement
	if(mBall.position.y > 0 && mBall.position.y < mWindow->GetDimensions().y - mPaddleHeight)
	{
		mPaddleLeft.position.y = mBall.position.y;
	}

	//ball movement
	mBall.position.y += mBallSpeedY * Time::deltaTime;
	mBall.position.x += mBallSpeedX * Time::deltaTime;

	if(Collision(mBall, mPaddleLeft) || Collision(mBall, mPaddleRight))
	{
		mBallSpeedX = -mBallSpeedX;
	}

	if(mBall.position.y < 0 )
	{
		mBallSpeedY = abs(mBallSpeedY);
	}
	else if(mBall.position.y > mWindow->GetDimensions().y - mBallSize)
	{
		mBallSpeedY = -abs(mBallSpeedY);
	}

	if(mBall.position.x < 0)
	{
		mBallSpeedX = abs(mBallSpeedX);
	}
	else if(mBall.position.x > mWindow->GetDimensions().x - mBallSize)
	{
		mBallSpeedX = -abs(mBallSpeedX);
	}
}

void Pong::Render()
{
	mRenderer->DrawRect(mBall);
	mRenderer->DrawRect(mPaddleRight);
	mRenderer->DrawRect(mPaddleLeft);
}

void Pong::OnInput(SDL_Event event)
{
	switch(event.type)
	{
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_UP)
			{
				mIsGoingUp = true;
				mIsGoingDown = false;
			}
			if(event.key.keysym.sym == SDLK_DOWN)
			{
				mIsGoingDown = true;
				mIsGoingUp = false;
			}
			break;

		case SDL_KEYUP:
			mIsGoingDown = false;
			mIsGoingUp = false;
			break;

		default:
			break;
	}
}

void Pong::Close()
{
}
