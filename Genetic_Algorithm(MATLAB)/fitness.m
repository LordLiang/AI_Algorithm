function [] = fitness( pop_size, chromo_size )
%fitness ������Ⱥ������Ӧ�ȣ��Բ�ͬ���Ż�Ŀ�꣬�˴���Ҫ��д
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
global fitness_value;%��Ⱥ����Ӧ��
% global fitness_val;%��Ӧ�ȳ߶ȱ任
global pop;%��ǰ������Ⱥ����

for i=1:pop_size
    fitness_value(i)=0.;
end

for i=1:pop_size
    
     for j=chromo_size-1:1
        pop(i,j)=xor(pop(i,j+1),pop(i,j)); %������ת������
     end
    
    for j=1:chromo_size
        if pop(i,j)==1
            fitness_value(i)=fitness_value(i)+2^(j-1);%������ת��Ϊʮ����
        end
    end
    fitness_value(i)=0.+fitness_value(i)*(10.-0.)/(2^chromo_size-1);%ת��Ϊ����������Ӧ����
    fitness_value(i)=fitness_value(i)+10.*sin(5.*fitness_value(i))+7.*cos(4.*fitness_value(i))+20.;
%     fitness_value(i)=fitness_value(i);
end
clear i;
clear j;

end

