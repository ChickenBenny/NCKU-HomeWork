
function RF = headFile_NI(filename)
file = fopen(filename, 'r');
rf = fread(file, 'int8');
fclose(file);

%% header
if rf(3)==0
    pulser='5900PR';
else
    pulser='AVB2-TB-C';
end
%這檔案一定是2進制的，如果是8bit，再加上正負的因數
%每一個字元最大的值就是127，然後你再按小算盤
%127*=就是16129，所以終於突破盲點了
%結果就是...他只是把「127進制」換成10進制而已
ScanSpeed=rf(4)*16129+rf(5)*127+rf(6);
Aline=rf(7)*16129+rf(8)*127+rf(9);	%印象中是換能器的array大小
DataLength=rf(10)*16129+rf(11)*127+rf(12);
SamplingRate=rf(13)*16129+rf(14)*127+rf(15);% MHz
Delay=rf(16)*16129+rf(17)*127+rf(18);  %暫且猜測他是us的單位
Vpp=rf(19)*16129+rf(20)*127+rf(21);% mV
XInterval=rf(22)*16129+rf(23)*127+rf(24);% μm
YInterval=rf(25)*16129+rf(26)*127+rf(27);
MoveTimes=rf(28)*16129+rf(29)*127+rf(30);% μm
Doppler=rf(31)*16129+rf(32)*127+rf(33);

%fprintf('size(rf) is %s\n', mat2str(size(rf)))
rf2 = rf(34:50033);


rf1 = reshape(rf2, DataLength, Aline, []); % reshape(A,2,2,[])= reshapes the 100 elements of A into a 2-by-2-by-25 array.
rf1 = rf1*Vpp/255;
RF = struct('rf', rf1, 'ScanSpeed', ScanSpeed, 'Aline', Aline, 'DataLength', DataLength,...
    'SamplingRate', SamplingRate, 'Delay', Delay, 'Vpp', Vpp, 'XInterval', XInterval,...
    'YInterval', YInterval, 'MoveTimes', MoveTimes, 'Doppler', Doppler, 'rf2', rf);

end
%主要輸出為RF，如果是_C0.dat就會輸出3D matrix
