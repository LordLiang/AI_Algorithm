function [] = plotGA( generation_size )
%plotGA ��ӡ�㷨��������
%generation_size: ��������
global fitness_avg;
x=1:1:generation_size;
y=fitness_avg-20;
plot(x,y);
end

