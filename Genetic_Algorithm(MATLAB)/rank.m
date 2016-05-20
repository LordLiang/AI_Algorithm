function [] = rank( pop_size,chromo_size )
%rank �Ը��尴��Ӧ�ȴ�С�������򣬲��ұ�����Ѹ���
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
global fitness_value;%��Ⱥ����Ӧ��
global fitness_table;%��Ⱥ�ۻ���Ӧ��
global fitness_avg;
global best_fitness;
global best_individual;
global best_generation;
global pop;%��ǰ������Ⱥ����
global G;%��ǰ���Ĵ���

for i=1:pop_size
    fitness_table(i)=0.;
end

key=1;
temp=1;
temp1(chromo_size)=0;
%����Ӧ�ȵ�������
for i=1:pop_size
    key=i;
    for j=i+1:pop_size
        if fitness_value(j)<fitness_value(key);
            key=j;
        end
    end
    if key~=i
        temp=fitness_value(i);
        fitness_value(i)=fitness_value(key);
        fitness_value(key)=temp;
        for k=1:chromo_size
            temp1(k)=pop(i,k);
            pop(i,k)=pop(key,k);
            pop(key,k)=temp1(k);
        end
    end
end
figure(1);
subplot(1,2,1);
q=0.;
for i=1:pop_size
    for j=1:chromo_size
        if pop(i,j)==1
            q=q+2^(j-1);
        end
    end
    q=0.+q*(10.-0.)/(2^chromo_size-1);
    plot(q,fitness_value(i)-20,'.','markersize',6)%Ĭ��Ϊ6
end
    
%�����ۻ���Ӧ��
for i=1:pop_size
    if i==1
        fitness_table(i)=fitness_table(i)+fitness_value(i);
    else
        fitness_table(i)=fitness_table(i-1)+fitness_value(i);
    end
end
%����ƽ����Ӧ��
fitness_avg(G)=fitness_table(pop_size)/pop_size;
%��¼��õĸ���
if fitness_value(pop_size)>best_fitness
    best_fitness=fitness_value(pop_size);
    best_generation=G;
    for j=1:chromo_size
        best_individual(j)=pop(pop_size,j);
    end
end

clear i;
clear j;
clear k;
clear min;
clear temp;
clear temp1;
end

    

