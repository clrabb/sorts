#!/usr/bin/python
import random


words = []
with open( "/usr/share/dict/words", "r" ) as f:
    for l in f:
        words.append( l.strip() )

random.shuffle( words )

for word in words:
    print word 




