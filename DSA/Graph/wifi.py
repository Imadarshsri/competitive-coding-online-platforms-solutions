# import subprocess as sp
# data = sp.check_output(['netsh', 'wlan', 'show', 'profiles']).decode(
#     'utf-8', errors="backslashreplace").split("\n")
# profiles = [i.split(":")[1][1:-1] for i in data if "All User Profile" in i]
# for i in profiles:
#     try:
#         results = sp.check_output(['netsh', 'wlan', 'show', 'profile', i, 'key = clear']).decode(
#             'utf-8', errors="backslashreplace")
#         results = [b.split(":")[1][1:-1]
#                    for b in results if "Key Content" in b]
#         try:
#             print("{:<30}| {:<}".format(i, results[0]))
#         except IndexError:
#             print("{:<30}| {:<}".format(i, ""))
#     except sp.CalledProcessError:
#         print("{:<30}| {:<}".format(i, "ECODING ERROR"))
# input("")
import subprocess

data = subprocess.check_output(['netsh', 'wlan', 'show', 'profiles']).decode('utf-8').split('\n')
profiles = [i.split(":")[1][1:-1] for i in data if "All User Profile" in i]
for i in profiles:
    results = subprocess.check_output(['netsh', 'wlan', 'show', 'profile', i, 'key=clear']).decode('utf-8').split('\n')
    results = [b.split(":")[1][1:-1] for b in results if "Key Content" in b]
    try:
        print ("{:<30}|  {:<}".format(i, results[0]))
    except IndexError:
        print ("{:<30}|  {:<}".format(i, ""))
input("")