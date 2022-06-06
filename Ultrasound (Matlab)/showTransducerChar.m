% input:
%     alineName- 檔名路徑
% output: 
%     d- time (x1軸)
%     alineSgn- time-domain訊號(y1軸)
%     f- frequency- (x2軸)
%     alineSgn- frequency-domain訊號(y2軸)

function [d, alineSgn, f, fftSgn] = showTransducerChar(alineName)
    close all
    
%   讀取資料
    data = headFile_NI(alineName);  %這邊已經是structure形式，找出對應訊號的component
    disp(data);
    signal = mean(data.rf,2);

%   快速傅立葉轉換
    spectrum = abs(fft(signal)).^2;

%   壓縮
    compressed_signal = 10*log10(spectrum/max(spectrum));

%   找出frequency-domain訊號>-6dB的資料範圍
%     plot(signal);
%     hold on;
%     plot(compressed_signal);

%   圖片輸出
    figure

    plot(signal,'linewidth', 2, 'Color', 'black','linestyle', '-');
    ax1 = gca;
    set(ax1,'XColor','b','YColor','b' ,'FontSize',18);
    xlabel("Time (\mus)",'FontWeight','bold','fontsize',18);
    ylabel("Amplitude (mV)",'FontWeight','bold','fontsize',18);
    
    ax2=axes('Position',get(ax1,'Position'),...
               'XAxisLocation','top',...
               'YAxisLocation','right',...
               'Color','none',...
               'XColor','blue','YColor','blue',...
               'XLim',[12,20],'ylim',[-6,0]);

    hold on;
    plot(compressed_signal,'linewidth', 2, 'Color', 'blue','linestyle', ':');
    legend('frequency domain', 'Location', 'southeast');
    xlabel('Frequency (MHz)','FontWeight','bold','fontsize',18,'blue');
    legend({'time domain', 'Location'}, 'southeast');
    ylabel('Magnitude (dB)','FontWeight','bold','fontsize',18, 'blue');
      
    
    
    %legend('time domain','frequency domain','Location','northwest');

