function [] = run_ga()
%run_ga ����������

elitism = true;%ѡ��Ӣ����
pop_size =50;%��Ⱥ��С
chromo_size = 17;%Ⱦɫ���С
generation_size = 200;%��������
cross_rate = 0.6;%�������
mutate_rate = 0.01;%�������

[m,n,p,q] = GeneticAlgorithm(pop_size, chromo_size, generation_size, cross_rate, mutate_rate,elitism);
disp "best individual"
m
disp "best fitness"
n
disp "x for best individual"
q
disp "generation number for best result"
p

clear;

end

