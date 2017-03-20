#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

import re
import subprocess as cmd
import os
import sys
import shlex

test_dir = ["/usr/share", "/usr/bin", "/sbin", "/bin", "/usr/sbin", "/usr/lib", "."]

#############################################################
# functions
os.system("rm -f their their_err mine mine_err")

def run_cmd_output(str, option):
    c = "nm " + option + " " + str
    with open("their", "w+") as out, open("their_err", "w+") as err:
        pipe = cmd.Popen(c.split(), stdout=out, stderr=err)
    pipe.wait()
    c = "../ft_nm " + option + " " + str
    with open("mine", "w+") as out, open("mine_err", "w+") as err:
        pipe = cmd.Popen(c.split(), stdout=out, stderr=err)
    pipe.wait()
    return 1

g_score = 0
g_total = 0

def ft_test_file(file, option):
    isExe = run_cmd_output(file, option)
    global g_score
    global g_total
    if (isExe == 1):
        count = cmd.check_output("diff their mine | wc -c", shell=True)
        count = int(count)
        g_total += 1
        if (count != 0):
            print("tests NM: \033[91mFAILED! \033[0m : " + file)
            #sys.exit(0)
        else:
            print("tests NM: \033[92mSUCCESS! \033[0m: " + file)
            g_score += 1
    #print("\n\033[96mSCORE: " + str(g_score) + " / " + str(g_total) + "\033[0m")

def ft_test_dir(dir, option):
    print("\033[93mTest NM \033[0m\033[94m" + os.path.abspath(dir) + "\033[0m")
    for file in os.listdir(dir):
        ft_test_file(dir + "/" + file, option)

def ft_test_dir_recur(dir, option):
    print("\033[93mTest NM \033[0m\033[94m" + os.path.abspath(dir) + "\033[0m")
    for root, directories, filenames in os.walk(dir):
        for filename in filenames:
            ft_test_file(filename, option)

for dir in test_dir:
    ft_test_dir(dir, "")

#print("\033[93mTest NM with option -Uvr \033[0m\033[94m" + os.path.abspath(".") + "\033[0m")
#ft_test_dir(".", "-Uvr")

print("\n\033[96mSCORE: " + str(g_score) + " / " + str(g_total) + "\033[0m")