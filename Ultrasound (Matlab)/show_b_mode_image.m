%{
input
    fullPath = "D:\����W���i�T���P�����޳N\�V�m�θ��\30MHz_wirephantom_B0.dat";
    dynamic_range = 42;
%}

function [us_image] = show_b_mode_image(fullPath, dynamic_range)
    
%   Ū�����
    file = fopen(fullPath, 'r');
    rf = fread(file, 'int8');
    fclose(file);
    
%   �p�GB-mode�v�����ɦW�O*_B1.dat(B�᭱�O�_��)�h�ݭn���k½��
    disp(height(rf));
    rf2 = rf(34:150033);
    signal = reshape(rf2, 1500, 100);

%   �p��RF
    ScanSpeed=rf(4)*16129+rf(5)*127+rf(6);
    Aline=rf(7)*16129+rf(8)*127+rf(9);	%�L�H���O���ྐྵ��array�j�p
    DataLength=rf(10)*16129+rf(11)*127+rf(12);
    SamplingRate=rf(13)*16129+rf(14)*127+rf(15);% MHz
    Delay=rf(16)*16129+rf(17)*127+rf(18);  %�ȥB�q���L�Ous�����
    Vpp=rf(19)*16129+rf(20)*127+rf(21);% mV
    XInterval=rf(22)*16129+rf(23)*127+rf(24);% �gm
    YInterval=rf(25)*16129+rf(26)*127+rf(27);
    MoveTimes=rf(28)*16129+rf(29)*127+rf(30);% �gm
    Doppler=rf(31)*16129+rf(32)*127+rf(33);
    
    rf2 = rf(34:150033);
    rf1 = reshape(rf2, DataLength, Aline, []); % reshape(A,2,2,[])= reshapes the 100 elements of A into a 2-by-2-by-25 array.
    rf1 = rf1*Vpp/255;
    RF = struct('rf', rf1, 'ScanSpeed', ScanSpeed, 'Aline', Aline, 'DataLength', DataLength,...
        'SamplingRate', SamplingRate, 'Delay', Delay, 'Vpp', Vpp, 'XInterval', XInterval,...
        'YInterval', YInterval, 'MoveTimes', MoveTimes, 'Doppler', Doppler, 'rf2', rf);
    
%   �p��X�b(��V�I�P�I�������Z����X interval����)�BY�b(�a�V�I�P�I�������Z����sampling rate����)
    d_x = ((1:Aline) * XInterval)/1000;
    Time = (((1:0.1:RF.DataLength)./RF.SamplingRate) + (RF.Delay./SamplingRate))./2;
    d_y = Time*1.54;
    
%   Hilbert transform  
    spectrum = abs(hilbert(signal));
    
%   ���Y
    compressed_signal = 20*log10(spectrum/max(spectrum(:)));

%   �ʺA�d��վ�&���W��
    us_image=(compressed_signal+dynamic_range)/dynamic_range*255;


%   �q��(plot)
    disp(RF);

    figure;
    image(d_x,d_y,us_image);
    colormap(gray(256));
    colorbar;
    %axis image;

    xlabel("Distance (mm)",'FontWeight','bold','fontsize',18);
    ylabel("Depth (mm)",'FontWeight','bold','fontsize',18);

