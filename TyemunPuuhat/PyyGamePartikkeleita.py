import math
import sys
import random
from math import cos, sin, sqrt
from random import randrange
import numpy

import pygame

width = 480
height = 320
screenCenterX = width/2
screenCenterY = height/2
amount = 1000 # explodes your pc when over 1000
traillenght = 2 # amount of points in trail, makes it smoother

pygame.init()
screen = pygame.display.set_mode((width, height))

class Quadtree: #after club activity
    def __init__(self, boundary, capacity=4):
        self.boundary = boundary
        self.capacity = capacity
        self.particles = []
        self.divided = False
        self.northwest = None
        self.northeast = None
        self.southwest = None
        self.southeast = None

class Particle:
    def __init__(self, x, y, mass, color):
        self.x = x
        self.y = y
        self.mass = mass
        self.radius = 1
        self.color = color
        self.xvel = 0 
        self.yvel = 0 
        self.max_force = 7.5
        self.threshold = 175
        self.friction = 2
        self.drag = 0.05
        self.trail = [] #previous positions array

    def update(self, particles):
        self.x += self.xvel/self.friction
        self.y += self.yvel/self.friction
        self.check_boundary(particles)
        self.interact_mouse()
        self.xvel *= (1 - self.drag)
        self.yvel *= (1 - self.drag)
        self.trail.append((self.x, self.y)) 
        if len(self.trail) > traillenght: 
            self.trail.pop(0)

    def check_boundary(self, particles):
        if self.x - self.radius <= 0:
            self.x = self.radius
            self.xvel = -self.xvel
        elif self.x + self.radius >= width:
            self.x = width - self.radius
            self.xvel = -self.xvel
        if self.y - self.radius <= 0:
            self.y = self.radius
            self.yvel = -self.yvel
        elif self.y + self.radius >= height:
            self.y = height - self.radius
            self.yvel = -self.yvel

    def interact_mouse(self):
        mouse_x, mouse_y = pygame.mouse.get_pos()
        dx = mouse_x - self.x
        dy = mouse_y - self.y
        distance = math.sqrt(dx * dx + dy * dy)
        if distance < self.threshold:
            force = 0
            for button, value in enumerate(pygame.mouse.get_pressed()):
                if value:
                    if button == 0:  # Left mouse button
                        force = self.max_force
                    elif button == 2:  # Right mouse button
                        force = -self.max_force
                    break
            angle = math.atan2(dy, dx)
            self.xvel -= force * math.cos(angle)
            self.yvel -= force * math.sin(angle)

particles = [Particle(random.randrange(0, width), random.randrange(0, height),1, (randrange(0,255), randrange(0,255), randrange(0,255))) for _ in range(amount)]

def main():

    while True:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                sys.exit()

        screen.fill((0, 0, 0))  # clear
        update_particles(particles)
        draw_particles(screen, particles)
        pygame.display.flip()
        pygame.time.Clock().tick(60)

def update_particles(particles):
    for particle in particles:
        particle.update(particles)

def draw_particles(screen, particles):
    for particle in particles:
        magnitude = math.sqrt(particle.xvel * particle.xvel + particle.yvel * particle.yvel) * 10 
        magnitude = numpy.clip(magnitude, 0, 255)
        newcolor = (magnitude,  255-magnitude, 255-magnitude)
        pygame.draw.circle(screen, newcolor, (particle.x, particle.y), particle.radius)

        #trail stuff
        for i in range(len(particle.trail) - 1):
            pygame.draw.line(screen, newcolor, (particle.trail[i][0], particle.trail[i][1]), (particle.trail[i+1][0], particle.trail[i+1][1]), 1)
main()