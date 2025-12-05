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
    ["-e",r"ciao\0141"],            
    ["-e", r"ciao\a"],            
    ["-e", r"ciao\b!"],           
    ["-e", r"ciao\c"],             
    ["-e", r"ciao\fnext"],         
    ["-e", r"ciao\nnext"],        
    ["-e", r"ciao\rTEST"],         
    ["-e", r"ciao\tnext"],        
    ["-e", r"ciao\vnext"],        
    ["-e", r"ciao\01412"],           
    ["-e", r"ciao\x61"],
    ["-e", r"ciao\x613"],
    ["-e", r"ciao\0619"],
    ["-e", r"ciao\09"],
    ["-e", r"ciao\ciao"],
    ["-e", r"ciao\0\niao"],
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
    
