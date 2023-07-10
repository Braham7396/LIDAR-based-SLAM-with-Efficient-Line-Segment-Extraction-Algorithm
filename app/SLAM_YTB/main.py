from SLAM_YTB import sensors, env
import math
import pygame

environment = env.buildEnvironment((600, 1200))
running = True

while running:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
    pygame.display.update()
