#! /usr/bin/env python
# -*- coding: utf-8 -*-
# vim:fenc=utf-8

import re
import subprocess as cmd
import os
import sys
import shlex

test_dir = [
    "/System/Library/CoreServices/Encodings/",
    "/usr",
    "/usr/libexec",
    "/usr/local",
    "/Library/Frameworks/",
    "/usr/share",
    "/usr/bin",
    "/sbin",
    "/bin",
    "/usr/sbin",
    "/usr/lib",
    "."]

#############################################################
# functions
os.system("rm -f their their_err mine mine_err")

def run_cmd_output(str):
    c = "nm " + str
    with open("their", "w+") as out, open("their_err", "w+") as err:
        pipe = cmd.Popen(c.split(), stdout=out, stderr=err)
    pipe.wait()
    c = "../ft_nm " + str
    with open("mine", "w+") as out, open("mine_err", "w+") as err:
        pipe = cmd.Popen(c.split(), stdout=out, stderr=err)
    pipe.wait()
    return 1

g_score = 0
g_total = 0

def ft_test_file(file):
    isExe = run_cmd_output(file)
    global g_score
    global g_total
    if (isExe == 1):
        count = cmd.check_output("diff their mine | wc -c", shell=True)
        count = int(count)
        g_total += 1
        if (count != 0):
            print("\033[91mFAILED! \033[0m : " + file)
            #sys.exit(0)
            g_score -= 1
        else:
            print("\033[92mSUCCESS! \033[0m: " + file)
            g_score += 1
    #print("\n\033[96mSCORE: " + str(g_score) + " / " + str(g_total) + "\033[0m")

def ft_test_multi_file(file):
    isExe = run_cmd_output(file)
    global g_score
    global g_total
    if (isExe == 1):
        count = cmd.check_output("diff their mine | wc -c", shell=True)
        count = int(count)
        g_total += 1
        if (count != 0):
            print("\033[91mFAILED! \033[0m : ")
            #sys.exit(0)
        else:
            print("\033[92mSUCCESS! \033[0m: ")
            g_score += 1

def ft_test_dir(dir):
    print("\033[93m######## Test NM All files in \033[0m\033[94m" + os.path.abspath(dir) + "\033[0m")
    multi_file = ""
    for file in os.listdir(dir):
        ft_test_file(dir + "/" + file)
        multi_file = multi_file + " " + dir + "/" + file
    print("\033[93m######## Test NM \033[0m\033[94m../ft_nm " + dir + "/* \033[0m")
    ft_test_multi_file(multi_file)

def ft_test_dir_recur(dir):
    print("\033[93m######## Test NM \033[0m\033[94m" + os.path.abspath(dir) + "\033[0m")
    for root, directories, filenames in os.walk(dir):
        for filename in filenames:
            ft_test_file(filename)

for dir in test_dir:
    ft_test_dir(dir)

print("\033[93mTest NM with option -v \033[0m\033[94m" + os.path.abspath(".") + "\033[0m")
ft_test_dir(".", "-v")

print("\n\033[96mSCORE: " + str(g_score) + " / " + str(g_total) + "\033[0m")
