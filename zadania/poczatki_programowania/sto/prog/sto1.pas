var a, b, k, m : longint;

begin
    read(a,b,k);
    m := a;
    if b < a then
        m := b;
    if k > m then
        writeln('0')
    else if 2*k > m then
        writeln((a+b-m) div k)
    else
        writeln(a div k + (b - k) div k + (a - k) div k + (b - 2*k) div k);
end.
