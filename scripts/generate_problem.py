import argparse
import os
import shutil 


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--number', action="store", dest="number")

    args = parser.parse_args()

    path = os.path.join(os.getcwd(), "problems", "problem_" + args.number)
    if os.path.exists(path):
        shutil.rmtree(path)
    shutil.copytree("template", path) 

    files = []
    dirlist = [path]

    while len(dirlist) > 0:
        for (dirpath, dirnames, filenames) in os.walk(dirlist.pop()):
            # remove .DS_store files
            filenames = [i for i in filenames if not i.startswith('.')]

            dirlist.extend(dirnames)
            files.extend(map(lambda n: os.path.join(*n), zip([dirpath] * len(filenames), filenames)))

    for file in files:
        print(file)
        with open(file, "rt") as f:
            x = f.read()
            
        with open(file, "wt") as f:
            x = x.replace('XXX', args.number)
            f.write(x)


if __name__ == "__main__":
    main()