int main()
{
    freopen("joc.in","r",stdin);
    freopen("joc.out","w",stdout);
    int i,n,S=0, j=1, cont=1    ;
    scanf("%d",&n);

    for(i=1; i<=n; ++i)
        scanf("%d",&gig[i]);
    for(i=1; i<=n; ++i)
        scanf("%d",&ion[i]);

    sort(gig+1, gig+n+1, cmp);
    sort(ion+1, ion+n+1, cmp);

    for(i=1;i<=n;++i)
        printf("%d",gig[i]);
    printf("\n");
    for(i=1;i<=n;++i)
        printf("%d",ion[i]);
    printf("\n");



    for(i=1; i<=n; ++i){
        printf("cont=%d j=%d\n",cont,j);
        for(j=cont ; j<=n && ion[j]>gig[i]; cont=++j)
            {
                printf("max=%d cele asmai mari=%d J=%d\n",gig[i], ion[j], j);

                S+=ion[j];
            }
    }

    printf("cont=%d %d\n",cont,S);
}

