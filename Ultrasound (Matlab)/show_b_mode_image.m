%{
input
    fullPath = "D:\生醫超音波訊號與成像技術\訓練用資料\30MHz_wirephantom_B0.dat";
    dynamic_range = 42;
%}

function [us_image] = show_b_mode_image(fullPath, dynamic_range)
    
%   讀取資料
    file = fopen(fullPath, 'r');
    rf = fread(file, 'int8');
    fclose(file);
    
%   如果B-mode影像的檔名是*_B1.dat(B後面是奇數)則需要左右翻轉
    disp(height(rf));
    rf2 = rf(34:150033);
    signal = reshape(rf2, 1500, 100);

%   計算RF
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
    
    rf2 = rf(34:150033);
    rf1 = reshape(rf2, DataLength, Aline, []); % reshape(A,2,2,[])= reshapes the 100 elements of A into a 2-by-2-by-25 array.
    rf1 = rf1*Vpp/255;
    RF = struct('rf', rf1, 'ScanSpeed', ScanSpeed, 'Aline', Aline, 'DataLength', DataLength,...
        'SamplingRate', SamplingRate, 'Delay', Delay, 'Vpp', Vpp, 'XInterval', XInterval,...
        'YInterval', YInterval, 'MoveTimes', MoveTimes, 'Doppler', Doppler, 'rf2', rf);
    
%   計算X軸(橫向點與點之間的距離跟X interval有關)、Y軸(縱向點與點之間的距離跟sampling rate有關)
    d_x = ((1:Aline) * XInterval)/1000;
    Time = (((1:0.1:RF.DataLength)./RF.SamplingRate) + (RF.Delay./SamplingRate))./2;
    d_y = Time*1.54;
    
%   Hilbert transform  
    spectrum = abs(hilbert(signal));
    
%   壓縮
    compressed_signal = 20*log10(spectrum/max(spectrum(:)));

%   動態範圍調整&正規化
    us_image=(compressed_signal+dynamic_range)/dynamic_range*255;


%   秀圖(plot)
    disp(RF);

    figure;
    image(d_x,d_y,us_image);
    colormap(gray(256));
    colorbar;
    %axis image;

    xlabel("Distance (mm)",'FontWeight','bold','fontsize',18);
    ylabel("Depth (mm)",'FontWeight','bold','fontsize',18);

