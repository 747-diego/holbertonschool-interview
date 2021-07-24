#!/usr/bin/python3
"""0. Log parsing."""
import sys
"""Write a script that reads stdin line by line and computes metrics."""


if __name__ == "__main__":
    status = {"200": 0, "301": 0, "400": 0,
              "401": 0, "403": 0, "404": 0, "405": 0, "500": 0}

    FileSize = 0
    counter = 0

    def getLog(line):
        """Parse the logs and gets status code."""
        try:
            lineParsed = line.split()
            statusCode = lineParsed[-2]
            if statusCode in status.keys():
                status[statusCode] += 1
            return int(lineParsed[-1])
        except Exception:
            return 0

    def printStdin():
        """Read stdin line by line and compute the metrics."""
        print("File size: {}".format(FileSize))
        for key in sorted(status.keys()):
            if status[key]:
                print("{}: {}".format(key, status[key]))

    try:
        for line in sys.stdin:
            FileSize += getLog(line)
            if counter % 10 == 0:
                printStdin()
            counter += 1
    except KeyboardInterrupt:
        printStdin()
        raise
    printStdin()
