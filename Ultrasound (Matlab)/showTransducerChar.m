% input:
%     alineName- �ɦW���|
% output: 
%     d- time (x1�b)
%     alineSgn- time-domain�T��(y1�b)
%     f- frequency- (x2�b)
%     alineSgn- frequency-domain�T��(y2�b)

function [d, alineSgn, f, fftSgn] = showTransducerChar(alineName)
    close all
    
%   Ū�����
    data = headFile_NI(alineName);  %�o��w�g�Ostructure�Φ��A��X�����T����component
    disp(data);
    signal = mean(data.rf,2);

%   �ֳt�ť߸��ഫ
    spectrum = abs(fft(signal)).^2;

%   ���Y
    compressed_signal = 10*log10(spectrum/max(spectrum));

%   ��Xfrequency-domain�T��>-6dB����ƽd��
%     plot(signal);
%     hold on;
%     plot(compressed_signal);

%   �Ϥ���X
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

