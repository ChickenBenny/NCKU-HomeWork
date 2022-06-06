
file = fopen('30MHz_steel_A0.dat', 'r');
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

rf = rf(34:end);

signal2D = reshape(rf,[DataLength,Aline]);% datalength: 一次訊號長度為500個點，1D->2D
signalAvg = mean(signal2D'); %返回 A 沿大小不等于 1

%% 利用傅立葉轉換計算頻率
samplePoint = 4096;
spectrum = abs(fft(signalAvg,samplePoint)).^2;

%% 計算dB 
dB = 10*log10(spectrum/max(spectrum));
dB = dB(1:2048);


x1=linspace(61*10^(-7),64*10^(-7),500);
x1 =x1/10^(-6);
y1=signalAvg;


%clf reset;
clf reset,ax1= axes('Position',[0.12,0.15,0.75,0.7]); %左邊界，下邊界，寬度，高度
hl1 = line(x1,y1,'Color','b'); % 第一條曲線
ax1 = gca; %設定主座標的顏色
set(ax1,'XColor','b','YColor','b' ,'FontSize',18);

set(get(ax1,'Xlabel'),'String','Time(μs)','Fontname', 'Arial','FontWeight','bold','FontSize',20) ;
set(get(ax1,'Ylabel'),'String','Amplitute(mV)','Fontname', 'Arial','FontWeight','bold','FontSize',20);
axis([6.125 6.4 -60 80]);

x2=linspace(1,500,2048);            %sampling_rate = 1000MHz,取一半為500MHz
y2=dB;

ax2 = axes('Position',get(ax1,'Position'),'XAxisLocation','top','YAxisLocation','right','Color','none','XColor','r','YColor','r' ,'FontSize',18);
hold on; %plot畫圖前會清空座標軸所以先hold
axis([26 35 -6 0]);

hl2 = line(x2,y2,'Color','r','Linestyle','--','LineWidth',(2),'Parent',ax2);
set(get(ax2,'Xlabel'),'String','Frequency( MHz )','Fontname', 'Arial','FontWeight','bold','FontSize',20);
set(get(ax2,'Ylabel'),'String','Magnitute( dB )','Fontname', 'Arial','FontWeight','bold','FontSize',20);

linehandles = [hl1, hl2];
cols = cell2mat(get(linehandles, 'color'));
[~, uidx] = unique(cols, 'rows', 'stable');
legend(linehandles(uidx), {'Time domain', 'Frequency domain'},  'Location', 'southeast');




