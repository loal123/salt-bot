#!/bin/zsh
export $(grep - v'^#'.env | xargs)
./build/salt_bot
