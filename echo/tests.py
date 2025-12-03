import subprocess

C_PROG = "./echo"            
SHELL_CMD = ["bash", "-c", "echo"]  



tests = [
    [""],
    ["'"],         
    ["\""],        
    ["'\"'"],      
    ["text"],
    ["-e"],
    ["-f"],
    ["-e", "ciao"],
    ["-e","ciao\\0141"],            
    ["-e", "ciao\\a"],            
    ["-e", "ciao\\b!"],           
    ["-e", "ciao\\c"],             
    ["-e", "ciao\\fnext"],         
    ["-e", "ciao\\nnext"],        
    ["-e", "ciao\\rTEST"],         
    ["-e", "ciao\\tnext"],        
    ["-e", "ciao\\vnext"],        
    ["-e", "ciao\\01412"],           
    ["-e", "ciao\\x61"],
    ["-e", "ciao\\x613"],
    ["-e", "ciao\\0619"],
]
              


def run(cmd, stdin):
    p = subprocess.Popen(
        cmd, stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        text=False
    )
    out, _= p.communicate(stdin)  
    return out, p.returncode

for t in tests:

    out_c, rc_c = run([C_PROG] + t,None)

  
    out_sh, rc_sh = run(["bash", "-c", "echo \"$@\"","--"]+t, None)
    if(out_c == out_sh):
        print("TEST OK")
    else:
        print("FAIL")
        print(f"Input: {(t)}")
        print(f"C output: {(out_c)}")
        print(f"SH output: {(out_sh)}")
        print("FAIL")
    
