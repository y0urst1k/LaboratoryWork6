#include "Box.h"
Box::Box(int id, int weight, int volume)
{
	if (weight < 0)
		weight = 0;
	if (volume < 0)
		volume = 0;

	this->weight = weight;
	this->volume = volume;
	this->id = id;
}

int Box::GetW() const
{
	return weight;
}

int Box::GetV() const
{
	return volume;
}

int Box::GetId() const
{
	return id;
}