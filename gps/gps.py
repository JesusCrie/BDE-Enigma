#!/bin/python
import random
import math

def generate_gps():
	lat = random.random()
	lat *= math.pi
	lat -= math.pi / 2
	lat = math.degrees(lat)

	lng = random.random()
	lng *= 360
	lng -= 180

	return [lat, lng]

def create_maps_link(coord):
	return 'http://www.google.com/maps/place/%s,%s' % (coord[0], coord[1])

if __name__ == '__main__':
	for _ in range(1000):
		la, ln = generate_gps()
		print('%f,%f' % (la, ln))
