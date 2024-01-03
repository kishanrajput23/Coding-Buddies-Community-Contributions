import encryption as cipher
import decryption as decipher   

try:
    import Tkinter as tk
except ImportError:
    import tkinter as tk

import gui_support

def vp_start_gui():
    '''Starting point when module is the main routine.'''
    global val, w, root
    root = tk.Tk()
    top = Toplevel1 (root)
    gui_support.init(root, top)
    root.mainloop()

w = None
def create_Toplevel1(root, *args, **kwargs):
    '''Starting point when module is imported by another program.'''
    global w, w_win, rt
    rt = root
    w = tk.Toplevel (root)
    top = Toplevel1 (w)
    gui_support.init(w, top, *args, **kwargs)
    return (w, top)

def destroy_Toplevel1():
    global w
    w.destroy()
    w = None

class Toplevel1:
    def __init__(self, top=None):
        '''This class configures and populates the toplevel window.
           top is the toplevel containing window.'''
        _bgcolor = '#d9d9d9'  # X11 color: 'gray85'
        _fgcolor = '#000000'  # X11 color: 'black'
        _compcolor = '#d9d9d9' # X11 color: 'gray85'
        _ana1color = '#d9d9d9' # X11 color: 'gray85'
        _ana2color = '#ececec' # Closest X11 color: 'gray92'

        top.geometry("902x600+385+154")
        top.minsize(148, 1)
        top.maxsize(1924, 1030)
        top.resizable(1, 1)
        top.title("CryptoSuit")
        top.configure(background="orange")

        self.text1 = tk.Entry(top)
        self.text1.place(relx=0.089, rely=0.333,height=174, relwidth=0.304)
        self.text1.configure(background="white")
        self.text1.configure(font="TkFixedFont")
        self.text1.configure(foreground="#000000")
        self.text1.configure(insertbackground="black")

        self.text1_1 = tk.Message(top)
        self.text1_1.place(relx=0.621, rely=0.333,height=174, relwidth=0.304)
        self.text1_1.configure(background="white")
        self.text1_1.configure(font="TkFixedFont")
        self.text1_1.configure(foreground="#000000")
        self.text1_1.configure(highlightbackground="#d9d9d9")
        self.text1_1.configure(highlightcolor="black")
        self.text1_1.configure(width=100)
        
        def call():
            plain_text =self.text1.get().upper()
            ans=cipher.encryptor(plain_text)
            #print(ans)
            self.text1_1.configure(text=ans)

        def get():
            encrypted_text =self.text1.get()
            x=decipher.decryptor(encrypted_text)
            self.text1_1.configure(text=x)

        self.Button1 = tk.Button(top)
        self.Button1.place(relx=0.443, rely=0.383, height=33, width=106)
        self.Button1.configure(activebackground="#ececec")
        self.Button1.configure(activeforeground="#000000")
        self.Button1.configure(background="#d9d9d9")
        self.Button1.configure(disabledforeground="#a3a3a3")
        self.Button1.configure(foreground="#000000")
        self.Button1.configure(highlightbackground="green")
        self.Button1.configure(highlightcolor="black")
        self.Button1.configure(pady="0")
        self.Button1.configure(text='''Encrypt''',command=call)

        self.Button1_2 = tk.Button(top)
        self.Button1_2.place(relx=0.443, rely=0.5, height=33, width=106)
        self.Button1_2.configure(activebackground="#ececec")
        self.Button1_2.configure(activeforeground="#000000")
        self.Button1_2.configure(background="#d9d9d9")
        self.Button1_2.configure(disabledforeground="#a3a3a3")
        self.Button1_2.configure(foreground="#000000")
        self.Button1_2.configure(highlightbackground="green")
        self.Button1_2.configure(highlightcolor="black")
        self.Button1_2.configure(pady="0")
        self.Button1_2.configure(text='''Decrypt''',command=get)

        self.Label1 = tk.Label(top)
        self.Label1.place(relx=0.356, rely=0.067, height=26, width=242)
        self.Label1.configure(background="orange")
        self.Label1.configure(disabledforeground="#a3a3a3")
        self.Label1.configure(foreground="black")
        self.Label1.configure(text='''MorseSuite''',font=("arial",30))

        self.Label2 = tk.Label(top)
        self.Label2.place(relx=0.1, rely=0.283, height=26, width=252)
        self.Label2.configure(background="orange")
        self.Label2.configure(disabledforeground="#a3a3a3")
        self.Label2.configure(foreground="#000000")
        self.Label2.configure(text='''USER INPUT''',font=("arial",15,'bold'))

        self.menubar = tk.Menu(top,font="TkMenuFont",bg=_bgcolor,fg=_fgcolor)
        top.configure(menu = self.menubar)

        self.Label3 = tk.Label(top)
        self.Label3.place(relx=0.632, rely=0.283, height=26, width=252)
        self.Label3.configure(background="orange")
        self.Label3.configure(disabledforeground="#a3a3a3")
        self.Label3.configure(foreground="#000000")
        self.Label3.configure(text='''OUTPUT''',font=("arial",15,'bold'))

if __name__ == '__main__':
    vp_start_gui()
