from PyPDF2 import PdfMerger
from tkinter import Tk
from tkinter.filedialog import askopenfilenames

Tk().withdraw()
files = list(askopenfilenames())
files.sort()

engine = PdfMerger()
for file in files:
    engine.append(file)

engine.write("merged_file.pdf")
engine.close()