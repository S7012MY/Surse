{$A+,B-,D+,E+,F-,G-,I+,L+,N-,O-,P-,Q-,R-,S-,T-,V+,X+,Y+}
{$M 16384,0,655360}
type mat=array[0..100,0..100]of integer;
var i,j,k,l,m,n,p,kk:longint;
    go,ok:boolean;
    fi,fo:text;
    t1,t2,sel:array[1..10000]of integer;
    c,f:^mat;
    luate:set of byte;
    st:array[1..1000]of integer;


procedure readdata;
begin
  assign(fi,'ghizi.in');
  assign(fo,'ghizi.out');
  reset(fi);
  readln(fi,n,k);
  for i:=1 to n do
      begin
        readln(fi,t1[i],t2[i]);
        if t1[i]=t2[i] then
           begin
             writeln('BULL ',i+1);
             inc(l);
             if l=10 then
                HALT;
           end;
      end;
  close(fi);
end;

procedure react(k:integer);
var i:integer;
begin
  for i:=1 to k-1 do
      if c^[st[i],st[i+1]]>f^[st[i],st[i+1]] then
         inc(f^[st[i],st[i+1]])
         else
         if f^[st[i+1],st[i]]>0 then
            dec(f^[st[i+1],st[i]])
            else
            begin
              writeln('EROARE!!!');
            end;
end;

procedure back;
var i:integer;
begin
  if st[kk-1]=100 then
     begin
       react(kk-1);
       go:=false;
       ok:=true;
     end;
  if not go then exit;

  for i:=100 downto 1 do
      if not(i in luate) then
         if (c^[st[kk-1],i]>f^[st[kk-1],i])
            or (f^[i,st[kk-1]]>0)
            then
            if go then
               begin
                 luate:=luate+[i];
                 st[kk]:=i;
                 inc(kk);
                 back;
                 dec(kk);
                 st[kk]:=0;
               end;
end;

procedure solve;
begin
  new(c);
  new(f);
  fillchar(c^,sizeof(c^),0);
  fillchar(f^,sizeof(f^),0);

  { graful }
  for i:=1 to n do
      inc(c^[t1[i],t2[i]]);

  { fluxul }
  for i:=1 to k do
      begin
        go:=true;
        ok:=false;
        luate:=[];
        fillchar(st,sizeof(st),0);
        st[1]:=0;
        kk:=2;
        back;
        if not ok then
           begin
             writeln('K e prea mare - am gasit ',i-1,' drumuri');
             writeln;
             halt;
           end;
      end;

  p:=0;
  for i:=1 to n do
      if f^[t1[i],t2[i]]>0 then
         begin
           sel[i]:=1;
           inc(p);
           dec(f^[t1[i],t2[i]]);
         end;

  if p=n then
     begin
       writeln('P=N');
       halt;
     end;

  l:=0;
  rewrite(fo);
  writeln(fo,p);
  for i:=1 to n do
      if sel[i]=1 then
         begin
           if l=1 then
              write(fo,' ');
           write(fo,i);
           l:=1;
         end;
  writeln(fo);
  close(fo);
{  writeln('OK');}
end;

begin
{  writeln('Starting...');}
  readdata;
  solve;
end.