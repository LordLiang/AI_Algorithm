function [] = crossover( pop_size,chromo_size,cross_rate )
%crossover ���㽻�����
%pop_size: ��Ⱥ��С
%chromo_size: Ⱦɫ�峤��
%cross_rate: �������
global pop;
for i=1:2:pop_size
    if(rand<cross_rate)
        cross_pos=round(rand*chromo_size);%���ѡȡ����λ��
        if or(cross_pos==0,cross_pos==1)
            continue;
        end
        for j=cross_pos:chromo_size
            temp=pop(i,j);
            pop(i,j)=pop(i+1,j);
            pop(i+1,j)=temp;
        end
    end
end
clear i;
clear j;
clear temp;
clear cross_pos;
end
