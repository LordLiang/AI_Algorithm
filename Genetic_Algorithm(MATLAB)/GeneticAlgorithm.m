function [m,n,p,q] = GeneticAlgorithm( pop_size,chromo_size,generation_size ,cross_rate,mutate_rate,elitism)
%GeneticAlgorithm ������
%pop_size: ������Ⱥ��С
%chromo_size: ����Ⱦɫ�峤��
%generation_size: �����������
%cross_rate: ���뽻�����
%mutate_rate: ����������
%elitism: �����Ƿ�Ӣѡ��
%m: �����Ѹ���
%n: ��������Ӧ��
%p: �����Ѹ�����ֵĴ���
%q: �����Ѹ����Ա���ֵ
global G;%��ǰ����
global fitness_value;%��ǰ����Ӧ�Ⱦ���
global best_fitness;%���������Ӧֵ
global fitness_avg;%����ƽ����Ӧֵ����
global best_individual;%������Ѹ���
global best_generation;%��Ѹ�����ִ�

fitness_avg=zeros(generation_size,1);

figure(1);
width=1200;%��ȣ�������
height=500;%�߶�
left=200;%����Ļ���½�ˮƽ����
bottem=100;%����Ļ���½Ǵ�ֱ����
set(gcf,'position',[left,bottem,width,height])
subplot(1,2,1);
x=0:0.01:10;
y1=x+10*sin(5*x)+7*cos(4*x);
plot(x,y1);
grid on;
hold on;


fitness_value(pop_size)=0.;
best_fitness=0;
best_generation=0;
initilize(pop_size,chromo_size);
for G=1:generation_size
    fitness(pop_size,chromo_size);
    rank(pop_size,chromo_size);
    selection(pop_size,chromo_size,elitism);
    crossover(pop_size,chromo_size,cross_rate);
    mutation(pop_size,chromo_size,mutate_rate);
end

subplot(1,2,2);
plotGA(generation_size);
m=best_individual;
n=best_fitness-20;
p=best_generation;
q=0.;

for j=chromo_size-1:1
        best_individual(j)=xor(best_individual(j+1),best_individual(j)); %������ת������
end
for j=1:chromo_size
    if best_individual(j)==1
        q=q+2^(j-1);
    end
end
q=0.+q*(10.-0.)/(2^chromo_size-1);
subplot(1,2,1);
plot(q,n,'*r')%Ĭ��Ϊ6

save G;
save fitness_value;
save best_fitness;
save fitness_avg;
save best_individual;
save best_generation;

clear i;
clear j;
end

